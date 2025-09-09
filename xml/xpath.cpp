/*
 * Website:
 *      https://github.com/wo3kie/cxxdojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++20 xpath.cpp -o xpath -I/usr/include/libxml2/ \
 *          -Lusr/lib/x86_64-linux-gnu/ -lxml2
 *
 * Usage:
 *      $ ./xpath xpath.xml "/doc/name"
 *      Mr. Bertoni
 *      Mr. Curcuru
 *      Mr. Kesselman
 *      Mr. Auriemma
 *
 * Usage:
 *      $ ./xpath xpath.xml "/doc/name/@first"
 *      David
 *      Shane
 *      Joseph
 *      Stephen
 */

#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <utility>

#include <libxml/parser.h>
#include <libxml/tree.h>
#include <libxml/xpath.h>
#include <libxml/xpathInternals.h>

template<typename Iterator>
struct Range {
  Range(Iterator begin, Iterator end)
      : m_begin(begin)
      , m_end(end) {
  }

  Iterator begin() {
    return m_begin;
  }
  Iterator end() {
    return m_end;
  }

private:
  Iterator m_begin;
  Iterator m_end;
};

struct XmlParser {
  XmlParser() {
    xmlInitParser();
  }

  ~XmlParser() {
    xmlCleanupParser();
  }
};

struct XmlDocDeleter {
  void operator()(xmlDocPtr ptr) const {
    xmlFreeDoc(ptr);
  }
};

struct XmlXPathContextDeleter {
  void operator()(xmlXPathContextPtr ptr) const {
    xmlXPathFreeContext(ptr);
  }
};

struct XmlXPathObjectDeleter {
  void operator()(xmlXPathObjectPtr ptr) const {
    xmlXPathFreeObject(ptr);
  }
};

struct XPathEval {
  typedef Range<xmlNode**> ResultSet;

public:
  void readFile(std::string const& filename) {
    m_doc.reset(xmlParseFile(filename.c_str()));

    if(! m_doc) {
      throw std::runtime_error("Error: unable to parse file " + filename);
    }

    m_ctx.reset(xmlXPathNewContext(m_doc.get()));
  }

  ResultSet run(std::string const& xpathExpr) {
    m_obj.reset(xmlXPathEvalExpression(BAD_CAST xpathExpr.c_str(), m_ctx.get()));

    if(! m_obj) {
      throw std::runtime_error("Error: unable to evaluate xpath expression " + xpathExpr);
    }

    xmlNodeSetPtr const nodes = m_obj->nodesetval;

    return {nodes->nodeTab, nodes->nodeTab + nodes->nodeNr};
  }

private:
  std::unique_ptr<xmlDoc, XmlDocDeleter> m_doc;
  std::unique_ptr<xmlXPathContext, XmlXPathContextDeleter> m_ctx;
  std::unique_ptr<xmlXPathObject, XmlXPathObjectDeleter> m_obj;
};

int main(int argc, char** argv) {
  if(argc != 3) {
    std::cerr << "Usage: " << argv[0] << " xmlfile xpath" << std::endl;
    return 1;
  }

  XmlParser parser;

  XPathEval xpathEval;
  xpathEval.readFile(argv[1]);

  for(auto item : xpathEval.run(argv[2])) {
    std::cout << item->children->content << std::endl;
  }

  return 0;
}

#include <cstring>
#include <iostream>

#include <libxml/parser.h>
#include <libxml/tree.h>

#include "../scope_exit.hpp"

void processProperties(xmlNode * node){
    for(xmlNode * currentNode = node; currentNode != NULL; currentNode = currentNode->next) {
        if(currentNode->type == XML_ELEMENT_NODE){
            if(std::strcmp("Title", (const char*)currentNode->name) == 0){
                std::cout << currentNode->name << ": " << currentNode->children->content << "\n";
            }
            else if(std::strcmp("Description", (const char*)currentNode->name) == 0){
                std::cout << currentNode->name << ": " << currentNode->children->content << "\n";
            }
            else if(std::strcmp("Url", (const char*)currentNode->name) == 0){
                std::cout << currentNode->name << ": " << currentNode->children->content << "\n\n";
            }

        }
    }
}

void processContent(xmlNode * node){
    for(xmlNode * currentNode = node; currentNode != NULL; currentNode = currentNode->next) {
        if(currentNode->type == XML_ELEMENT_NODE){
            if(std::strcmp("properties", (const char*)currentNode->name) == 0){
                processProperties(currentNode->children);
            }
        }
    }
}

void processEntry(xmlNode * node){
    for(xmlNode * currentNode = node; currentNode != NULL; currentNode = currentNode->next) {
        if(currentNode->type == XML_ELEMENT_NODE){
            if(std::strcmp("content", (const char*)currentNode->name) == 0){
                processContent(currentNode->children);
            }
        }
    }
}

void processFeed(xmlNode * node){
    for(xmlNode * currentNode = node; currentNode != NULL; currentNode = currentNode->next) {
        if(currentNode->type == XML_ELEMENT_NODE){
            if(std::strcmp("entry", (const char*)currentNode->name) == 0){
                processEntry(currentNode->children);
            }
        }
    }
}


void processRoot(xmlNode * node){
    for(xmlNode * currentNode = node; currentNode != NULL; currentNode = currentNode->next) {
        if(currentNode->type == XML_ELEMENT_NODE){
            if(std::strcmp("feed", (const char*)currentNode->name) == 0){
                processFeed(currentNode->children);
            }
        }
    }
}

int main(int argc, char **argv){
    auto xmlCleanupParserExit = make_scope_exit( [](){ xmlCleanupParser(); } );

    xmlDoc * doc = xmlReadFile(argv[1], NULL, 0);
    auto xmlFreeDocExit = make_scope_exit( [&doc](){ xmlFreeDoc(doc); } );

    if(doc == NULL){
        std::cerr << "error: could not parse file " << argv[1] << std::endl;
        return 1;
    }

    processRoot(xmlDocGetRootElement(doc));
    return 0;
}

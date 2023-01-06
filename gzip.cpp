#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include <boost/iostreams/copy.hpp>
#include <boost/iostreams/filter/gzip.hpp>
#include <boost/iostreams/filtering_streambuf.hpp>

namespace iostreams = boost::iostreams;

struct GzipCompressor {
  explicit GzipCompressor(std::ostream& output)
      : ostream_(&buffer_) {
    buffer_.push(iostreams::gzip_compressor());
    buffer_.push(output);
  }

  std::ostream& getStream() noexcept {
    return ostream_;
  }

private:
  std::ostream ostream_;
  iostreams::filtering_streambuf<iostreams::output> buffer_;
};

struct GzipDecompressor {
  explicit GzipDecompressor(std::istream& input)
      : istream_(&buffer_) {
    buffer_.push(iostreams::gzip_decompressor());
    buffer_.push(input);
  }

  std::istream& getStream() noexcept {
    return istream_;
  }

private:
  std::istream istream_;
  iostreams::filtering_streambuf<iostreams::input> buffer_;
};

int main() {
  std::string text("Overview\n"
                   "\n"
                   "The class templates basic_gzip_compressor and basic_gzip_decompressor perform"
                   "compression and decompression based on the GZIP format ([Deutsch3]) using"
                   "Jean-loup Gailly's and Mark Adler's zlib compression library ([Gailly])."
                   "They are implementation as derived classes of the Zlib Filters. The difference"
                   "between the GZIP and ZLIB formats is that data in the GZIP contains more header"
                   "information and a different checksum ([Deutsch1], [Deutsch3]).\n"
                   "\n"
                   "Currently, basic_gzip_compressor is a DualUseFilters, but basic_gzip_compressor"
                   "is only an InputFilter.\n"
                   "\n"
                   "Acknowledgments\n"
                   "\n"
                   "The gzip Filters were influences by the work of Jeff Garland ([Garland]) and"
                   "Jonathan de Halleux ([de Halleux]).\n"
                   "Thanks to Jean-loup Gailly and Mark Adler for making their excellent library"
                   "available to the public with a Boost-compatible license.\n"
                   "...\n"
                   "\n"
                   "To read more visit:\n"
                   "http://www.boost.org/doc/libs/1_59_0/libs/iostreams/doc/classes/gzip.html\n");

  {
    std::ofstream compressedFile("gzip.gz", std::ios_base::out | std::ios_base::binary);
    GzipCompressor gzipCompressor(compressedFile);
    std::ostream& file = gzipCompressor.getStream();

    file << text << std::endl;
  }

  {
    std::ifstream compressedFile("gzip.gz", std::ios_base::in | std::ios_base::binary);
    GzipDecompressor gzipDecompressor(compressedFile);
    std::istream& file = gzipDecompressor.getStream();

    std::string line;
    while(std::getline(file, line)) {
      std::cout << line << std::endl;
    }
  }
}

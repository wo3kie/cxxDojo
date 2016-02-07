/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++11 xml.cpp -o xml
 *
 * Usage:
 *      $ ./xml
 */

#include <fstream>
#include <iostream>
#include <string>

#include <boost/property_tree/xml_parser.hpp>
#include <boost/property_tree/ptree.hpp>

void print( boost::property_tree::ptree pt, int indent = 0 ){
    for( auto const & element : pt ){
        if( element.first == "name" ){
            auto const xmlAttrs = element.second;
            auto const attrs = xmlAttrs.get_child( "<xmlattr>" );

            auto const elementName = element.first;
            auto const elementValue = xmlAttrs.get_value< std::string >();

            std::cout
                << std::string( indent, ' ' )
                << elementName << " " << elementValue
                << std::endl;

            for( auto const & attr : attrs ){
                auto const attributeName = attr.first;
                auto const attributeValue = attr.second.get_value< std::string >();

                std::cout
                    << std::string( indent + 4, ' ' )
                    << attributeName << ": " << attributeValue
                    << std::endl;
            }
        }
        else if( element.first == "doc" ){
            std::cout
                << std::string( indent, ' ' )
                << element.first
                << std::endl;
        }
        
        print( element.second, indent + 4 );
    }
}

int main(){
    std::ifstream input( "./xml.xml" );

    boost::property_tree::ptree propertyTree;
    read_xml( input, propertyTree );
    print( propertyTree );

    return 0;
}


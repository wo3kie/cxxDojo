/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++11 ls.cpp -o ls -lboost_filesystem -lboost_system
 *
 * Usage:
 *      $ ./ls .
 *      F "./get.request.cpp"
 *      F "./par.cpp"
 *      F "./barrier.cpp"
 *      F "./ls.cpp"
 *      F "./scope_exit.cpp"
 *      ...
 */

#include <iostream>

#include <boost/filesystem.hpp>

namespace fs = boost::filesystem;

void printDirectoryContent( fs::path const & path )
{
    namespace fs = boost::filesystem;
   
    fs::directory_iterator current( path );
    fs::directory_iterator const end;

    for( /*empty*/ ; current != end ; ++ current )
    {
        fs::directory_entry entry = * current;

        if( fs::is_regular_file( entry.path() ) ){
            std::cout << "F " << entry << std::endl;
        }
        else if( fs::is_directory( entry.path() ) ){
            std::cout << "D " << entry << std::endl;
        }
        else if( fs::is_symlink( entry.path() ) ){
            std::cout << "L " << entry << std::endl;
        }
        else{
            std::cout << "? " << entry << std::endl;
        }
    }
}

int main( int argc, char * argv[] )
{
    if( argc != 2 )
    {
        std::cerr << "Usage: " << argv[0] << " directoryName" << std::endl;
        return 1;
    }
    else
    {
        printDirectoryContent( argv[1] );
        return 0;
    }
}


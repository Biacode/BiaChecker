/* The MIT License
 *
 * Copyright (c) 2015 Bia-Code http://biacode.com
 * Author Arthur Asatryan biacoder@gmail.com
 * GIT: https://github.com/bia-code
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include <dirent.h>
#include <iostream>
#include <fstream>
#include "FileListHelper.h"
#include "md5wrapper.h"

using namespace std;

//
// Created by Arthur on 5/3/2015.
//

void FileListHelper::processDirectory(string directory) {
    string dirToOpen = path + directory;
    auto dir = opendir(dirToOpen.c_str());
    //set the new path for the content of the directory
    path = dirToOpen + "/";
    ofstream myFile(out_path, ios::app);
    if (myFile.is_open()) {
        myFile << "<folder>" << dirToOpen.c_str() << "</folder>" << endl;
    }
    else cout << "Unable to open file";;
    current_path = ((string) dirToOpen.c_str() + "/");
    if (NULL == dir) {
        cout << "could not open directory: " << dirToOpen.c_str() << endl;
        return;
    }
    auto entity = readdir(dir);
    while (entity != NULL) {
        processEntity(entity);
        entity = readdir(dir);
    }
    //we finished with the directory so remove it from the path
    path.resize(path.length() - 1 - directory.length());
    closedir(dir);
}

void FileListHelper::processEntity(struct dirent *entity) {
    //find entity type
    if (entity->d_type == DT_DIR) {
        //it's an directory
        //don't process the  '..' and the '.' directories
        if (entity->d_name[0] == '.') {
            return;
        }
        //it's an directory so process it
        processDirectory(string(entity->d_name));
        return;
    }
    if (entity->d_type == DT_REG) {
        //regular file
        processFile(string(entity->d_name));
        return;
    }
    //there are some other types
    cout << "Not a file or directory: " << entity->d_name << endl;
}

void FileListHelper::processFile(string file) {
    ofstream myFile(out_path, ios::app); // open file with append to end permission
    if (myFile.is_open()) {
        myFile << "<file>" << file.c_str() << "</file>" << endl;
        myFile << "<fullPath>" << current_path + file.c_str() << "</fullPath>" << endl;
        // get file hash sum
        md5wrapper md5;
        // will store the md5 hash of a file called test.txt in a string hash1
        std::string hash = md5.getHashFromFile(current_path + file.c_str());
        myFile << "<hash>" << hash << "</hash>" << endl;
        cout << ".";
    }
}

string FileListHelper::getOutPath() {
    return out_path;
}

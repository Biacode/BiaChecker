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

#ifndef BIA_CHECKER_FILEHELPER_H
#define BIA_CHECKER_FILEHELPER_H


#include <bits/stringfwd.h>
#include <bits/basic_string.h>

//
// Created by Arthur on 5/3/2015.
//

class FileListHelper {

private:
    // checking directory E.x
    std::string path = "D:\\what\\need\\to\\check";
    // output directory with file name (will create itself if no file) E.x
    std::string out_path = "C:\\Users\\Arthur\\ClionProjects\\bia-checker\\foo.xml";
    // store that where is checker is searching in current iteration (for hash and fullPath)
    std::string current_path = "";

public:
    // process if it's file
    void processFile(std::string file);

    // pick up processFile or processDirectory
    void processEntity(struct dirent *entity);

    // process if it's directory (put directory if need specific one or leave "")
    void processDirectory(std::string directory);

    std::string getOutPath();

};


#endif //BIA_CHECKER_FILEHELPER_H

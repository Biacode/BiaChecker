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

#include <iostream>
#include <fstream>
#include "FileListHelper.h"

using namespace std;

//
// Created by Arthur on 5/3/2015.
//

int main() {
    FileListHelper fileHelper = FileListHelper();
    ofstream myFile(fileHelper.getOutPath(), ios::app);
    if (myFile.is_open()) {
        myFile << "<directory>\n";
        myFile.flush(); // output current buffer or it will be mixed
        fileHelper.processDirectory("");
        myFile << "</directory>";
        myFile.flush(); // clear buffer and output to file
        myFile.close();
    }
    return 0;
}

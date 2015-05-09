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

//include protection
#ifndef MD5WRAPPER_H
#define MD5WRAPPER_H

//basic includes
#include <string>

//forwards
class MD5;

class md5wrapper {
private:
    MD5 *md5;

    /*
     * internal hash function, calling
     * the basic methods from md5.h
     */
    std::string hashit(std::string text);

    /*
     * converts the numeric giets to
     * a valid std::string
     */
    std::string convToString(unsigned char *bytes);

public:
    //constructor
    md5wrapper();

    //destructor
    ~md5wrapper();

    /*
     * creates a MD5 hash from
     * "text" and returns it as
     * string
     */
    std::string getHashFromString(std::string text);

    /*
     * creates a MD5 hash from
     * a file specified in "filename" and
     * returns it as string
     */
    std::string getHashFromFile(std::string filename);
};


//include protection
#endif

/*
 * EOF
 */

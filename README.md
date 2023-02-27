# SimpleC - Your C code: Simplified

### Demonstration:
```c
#include <stdio.h>
#include "simplec.h"

int main(){
  
  // whoami?
  const char *whoami = whoami();
  printf("Logged in as: %s", whoami);
  
  // create hello.txt
  create_file("hello.txt");
  
  // hello.txt exists?
  file_exists("hello.txt");
  
  //copy wraith.bin > wraith_copy.bin
  binary_copy("wraith.bin", "wraith_copy.bin");
}
```

### Please compile it with gcc, because clang has issues compiling SimpleC for some reason.

I created this small header in order to skip re-wrting the same code all over again and use utilites from scratch and to help new developers coming from Python on a simplified way.
## Features:

`whoami();` : A whoami implementation for unix and for Windows NT
<br>
`create_file(const char *filename);` : Create a file on an existing directory
<br>
`file_exists(const char *filename);` : Check whether a file exists on a directory
<br>
`binary_copy(const char *indir, const char *outdir);` : Makes a copy of a binary on a specified directory.

## Usage:

Simply include SimpleC and then start using it (see features section above).


## License (MIT):

Copyright (c) 2023 Karapatakis Aggelos

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

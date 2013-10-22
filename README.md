DB
==
Build<br>

<b>Windows</b><br>
1)Boost<br>
download http://sourceforge.net/projects/boost/files/boost/1.53.0/boost_1_53_0.7z/download <br>
extract to extern_lib/<br>
2)Build boost:<br>
bootstrap.bat gcc<br>
bjam --with-filesystem --with-system --toolset=gcc stage -j2 

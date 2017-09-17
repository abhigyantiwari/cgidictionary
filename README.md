# cgidictionary

  <p align="center">
  <img src="https://i.imgur.com/K9Xx0A8.png" alt="screenshot cgi app"> 
  </p>
  
This is CGI based dictionary web app using "the GNU collaborative international dictionary of English", C++ and pugiXML library 

Using pugiXML (XML parsing API for C++) I wrote a C++ application which searches in dictionary XML files I downloaded named GCIDE.

It is CGI (google it) based; so that server can host the CGI file I compiled (not .exe) for browser.

dict.cgi file along with headers, cpp files and XML folder should be copied to cgi-bin folder of the server.

Whenever in a mood to change the web design/functionality just recompile the cgidict.cpp file with changes (assuming you know CGI) along
with pugixml.cpp file linked together.

Note: I just made this project to learn about CGI and for the sake of making C++ web app when I was learning php too. So search feature 
is not that accurate. Free to distribute/sell/edit etc.

#include <string.h>
#include <cstring>
#include <stdlib.h>
#include "styles.h"
#include "pugixml.hpp"

//Initialize HTML Document and end using constructor

class initHTML
{
public:
	initHTML(const std::string title);
	~initHTML();
};

initHTML::initHTML(const std::string title)
{
	std::cout << "Content-type:text/html\n\n";
	std::cout << "<html><head><title>" << title 
			  << "</title>";
			  
	//Call this function from styles.h to set styles
	
	css::setStyle();
	std::cout << "</head><body>";
}

initHTML::~initHTML()
{
	std::cout << "</body></html>";
}

//Get word meaning from XML dictionary using pugiXML library

class fetchMeaning
{
private:
	bool found;
public:
	int wordIs(char keyw[20])
	{
		//std::cout<<"<script>document.getElementById('meaning-text').textContent='"<<keyw<<"'</script>";
		char *temp;
		temp = keyw;
		if(isupper(keyw[0])==0){temp[0]=tolower(keyw[0]);};
		char temp2[1] = {temp[0]};
		char filename[18] = {"xml/gcide_"};
		strcat(filename,temp2);
		strcat(filename,".xml");
		pugi::xml_document dict;
		pugi::xml_parse_result result = dict.load_file(filename);
		if(!result)
		{
			std::cout << result.description();
		}
		else
		{
			for(pugi::xml_node root = dict.first_child().first_child(); root; root=root.next_sibling())
			{
				found=false;
				if(root==NULL)
					std::cout<<"error";
					//cout<<root.child_value("ent");
				if(strcmp((char*)root.child_value("ent"),keyw)==0)
				{
					std::cout << "<script>document.getElementById('meaning-text').textContent='"
							  << root.child_value("def")
							  << "'</script>";
					found=true;
					break;
				}
			}
			if(found)
			{
				std::cout << "<script>document.getElementById('meaning-text').textContent='"
							  << "Srry Not Found...\nTry another?"
							  << "'</script>";
			}
		}
		return 0;
	}	
};

int main(int argc, char** argv, char **envp)
{
	//Passing title and initializing HTML:
	
	initHTML init("CGI Dictionary");
	std::cout << "<div class='form-container'>"
			  << "<form method='GET' action=''>"
			  << "<label for='keyword'>Enter Keyword:</label>"
			  << "<input id='input-key' type='text' name='keyword'>"
			  << "<input id='submit-btn' type='submit' name='submit' value='Get Meaning'>"
			  << "</form>"
			  << "<div id='meaning-container'><p id='meaning-text'></p></div>"
			  << "</div>";
			  
	//Getting Querry String from HTTP:
	
	char *query, *token, keyword[20];
	int temp;
	bool check;
	if(query=getenv("QUERY_STRING"))
	{
		char buffer[256];
		strncpy(buffer,query,sizeof(buffer));
		token = strtok(buffer,"&");
		sscanf(token,"keyword=%s",keyword);
		temp=0;
		
		while(keyword[temp])
		{
			if(isalnum(keyword[temp]))
				check = true;
			else
				check = false;
			temp++;
		}
		fetchMeaning keywd;
		if(check==true)
		{
			keywd.wordIs(keyword);
		}
	}
			  
	return 0;
}
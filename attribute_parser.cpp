// Test cases
//***********************************************************
/*
4 3
<tag1 value = "HelloWorld">
<tag2 name = "Name1">
</tag2>
</tag1>
tag1.tag2~name
tag1~name
tag1~value
*/
//************************************************************
/*
16 15
<tag1 v1 = "123" v2 = "43.4" v3 = "hello">
</tag1>
<tag2 v4 = "v2" name = "Tag2">
<tag3 v1 = "Hello" v2 = "World!">
</tag3>
<tag4 v1 = "Hello" v2 = "Universe!">
</tag4>
</tag2>
<tag5>
<tag7 new_val = "New">
</tag7>
</tag5>
<tag6>
<tag8 intval = "34" floatval = "9.845">
</tag8>
</tag6>
tag1~v1
tag1.v1
tag1~v2
tag1~v3
tag4~v2
tag2.tag4~v1
tag2.tag4~v2
tag2.tag3~v2
tag5.tag7~new_val
tag5~new_val
tag7~new_val
tag6.tag8~intval
tag6.tag8~floatval
tag6.tag8~val
tag8~intval
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
#include <sstream>
using namespace std;

typedef struct tag
{
	string tagName;
	struct tag *parent;
	map<string, string> attribute_value;	 
}TAG;

typedef struct query
{
	vector<string> parentList;
	string attribute;
}QUERY;

void parseHRML(vector<string> source, vector<TAG *> &tagList);
void processQueries(vector<string> Queries, vector<TAG *> &tagList);
bool Is_Attribute_Found(TAG *ptrTag, QUERY &obj);

int main() {
    vector<string> sourceLines;
	vector<string> queries;
	int N, NQ;
	cin >> N >> NQ ;

	string sline;
	getline(cin, sline);		
	for(auto i = 0; i < N; i++)
	{
		getline(cin, sline);		
		sourceLines.push_back(sline);
	}

	for(auto i = 0; i < NQ; i++)
	{
		getline(cin, sline);
		queries.push_back(sline);
	}

	vector<TAG *> tagList;
	parseHRML(sourceLines, tagList);
	processQueries(queries, tagList);
    return 0;
}

void parseHRML(vector<string> source, vector<TAG *> &tagList)
{
	int N = source.size();	
	stack<TAG *> tagTracker;
	for(auto i = 0; i < N; i++)
	{
		vector<string> tokens;
		istringstream ss(source[i]);
		while(ss)
		{
			string token;
			ss >> token;
			tokens.push_back(token);
		}
		int numTokens = tokens.size();
		if(tokens[0][0] == '<' && tokens[0][1] == '/')
		{
			tagTracker.pop();
			continue;
		}
				
		TAG *ptrTag = new TAG();
		if(tagTracker.empty())
			ptrTag->parent = NULL;
		else
			ptrTag->parent = tagTracker.top();

		for(auto j = 0; j < numTokens; j++)
		{
			if(tokens[j][0] == '<')
			{
				if(tokens[j][tokens[0].size()-1] == '>')  // emtpy tag
					ptrTag->tagName = tokens[j].substr(1, tokens[0].size()-2);
				else
					ptrTag->tagName = tokens[j].substr(1);
				tagTracker.push(ptrTag);
			}

			if(tokens[j] == "=")
			{
				string attName = tokens[j-1];
				string attValue;
				int pos = tokens[j+1].find(">");
				if(pos == string::npos)
					attValue = tokens[j+1].substr(1, tokens[j+1].size()-2);
				else
					attValue = tokens[j+1].substr(1, pos-2);

				ptrTag->attribute_value[attName] = attValue;
				j++;
			}
		}
		tagList.push_back(ptrTag);
	}
}

void processQueries(vector<string> Queries, vector<TAG *> &tagList)
{
	int NQ = Queries.size();
	for(auto i = 0; i < NQ; i++)
	{
		QUERY objQuery;		
		string tags;
		size_t pos = Queries[i].find("~");
		if(pos != string::npos)
		{
			objQuery.attribute = Queries[i].substr(pos+1);
			tags = Queries[i].substr(0, pos);
		}
		
		if(tags.size() > 0)
		{
			char *pch = NULL;
			char *token = NULL;
			pch = strtok(const_cast<char*>(tags.c_str()), ".");
			char *strDest = NULL;
			while(pch != NULL)
			{
				int len = strlen(pch);
				strDest = new char[len+1];
				strcpy(strDest, pch);
				strDest[len] = '\0';

				objQuery.parentList.push_back(string(strDest));
				pch = strtok(NULL, ".~");
			}
		}		
		
		int tagCount = tagList.size();
		bool found = false;
		
		if(objQuery.attribute.size() > 0)
		{
			for(auto j = 0; j < tagCount; j++)
			{
				found = Is_Attribute_Found(tagList[j], objQuery);
				if(found)
				{
					cout << tagList[j]->attribute_value[objQuery.attribute] << endl;
					break;
				}			
			}
		}

		if(found == false)		
		{
			cout << "Not Found!" << endl;
		}
	}
}

bool Is_Attribute_Found(TAG *ptrTag, QUERY &obj)
{
	bool found = false;
	
	if(ptrTag->attribute_value.find(obj.attribute) != ptrTag->attribute_value.end())
	{
		auto ritr = obj.parentList.rbegin();		
		string parentName = ptrTag->tagName;
		TAG *parent = ptrTag;
		while(ritr != obj.parentList.rend() && parent != NULL)
		{
			if(parent->tagName != *ritr)
			{
				return false;
			}
			parent = parent->parent;
			ritr++;
		}

		if(ritr == obj.parentList.rend() && parent == NULL)
		{
			found = true;
		}
		
	}
	return found;
}
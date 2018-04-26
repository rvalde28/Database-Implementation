# teamproj1
JSON PARSER WORK SO FAR:
Functions provided: Creates database based on JSON object for type business only at the moment. 

PLEASE READ ME:

I added two namespaces.  One is db and the other db::parser. Please include them in your files.  Otherwise, the query function wont work.  Thank you!


RUBEN READ ME: Please be sure to change the include statements so you don't have linker errrors.  Table.cpp needs to be done.  However, query should work.  

MADE SOME CHANGES TO TABLE:
Protected member vector attributes changed from type std::string to type Attribute.  Table(vector<std::string> attributes) changed to have underscore in name to help with writing from the attributes in typedef to attribute in protected member.  Not a true copy constructor as the value attributes do not stay with the copied attributes.

............................................................................

Checkpoint 2 (Due October 1):
We all are generating our own test cases
We will compare later and will delete/modify/add as needed

Responsibilites
  - Veena - Database.h/Database.cpp
  - Wyatt - Table.h/Table.cpp
  - Ruben - Record.h/Record.cpp

............................................................................

Checkpoint 1:
We are implementing an API.  

Our first checkpoint is September 24, 2017 where we need to have:
  - Team Organization
  - API definition
  - API header and stub libraries
  - Report about how we did all the above

We also need to have separate branches for all the work.  The master branch is basically like the final draft.  Your branch is like a rough draft.  Before merging into the final branch, assign another team member to review your work/pull request.  This way, at least two out of three people will know why the work was added to the final branch.  We also have issues and a project to track progress.  

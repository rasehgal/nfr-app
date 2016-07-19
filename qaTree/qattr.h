#ifndef __QATTR_H__
#define __QATTR_H__
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

// constructor for quality attribute node
struct qaNode {
   string ID;
   string src;
   string stim;
   string env;
   string afct; // artifact information
   string rsp; // response
   string rspm; // response measure
   vector<qaNode*> children; // node children of this n-way node-- used for edit function to handle multiple versions
};

// constructor for quality attribute tree
struct qaTree {
   string name;
   vector<qaTree*> cachildren; // category tree children of this n-way tree
   vector<qaNode*> children; // attribute node children of this n-way tree
};

// newTree
// input: string representing tree name/identity
// output: new qaTree 
qaTree* newTree(string name);

// adoptcat
// input: project root, category root tree
// output: returns project root with new category
// adopted as a cachild of the project root
qaTree* adoptcat (qaTree* proj, qaTree* cat);

// newattr
// input: strings representing desired attribute's ID, source,
// stimuli, environment, artifact, response, response measure
// information
// output: returms newly created qaNode representing attribute/attr 
// information
 qaNode* newattr(string id, string src, string stim, string env, string afct,
         string rsp, string rspm);

// adoptattr
// input: category root tree, existing node representing
// attribute/attr information desired
// output: returns category root tree with new attribute
// adopted as a child of the category root
qaTree* adoptattr(qaTree* cat, qaNode* attr);

#endif

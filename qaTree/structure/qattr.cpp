// qattr.cpp

#include <assert.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <set>
#include "qattr.h"

// create new qaTree
qaTree* newTree (string name) {
   qaTree* tree = new qaTree();
   tree->name = name;
   return tree;
}

// create new category branch
qaTree* adoptcat (qaTree* proj, qaTree* cat) {
   proj->cachildren.push_back(cat);
   return proj;
}

// create new attribute to be added to a category branch
qaNode* newattr(string id, string src, string stim, string env, string afct,
string rsp, string rspm) {
   qaNode* attr = new qaNode();
   attr->ID = id;
   attr->src = src;
   attr->stim = stim;
   attr->env = env;
   attr->afct = afct;
   attr->rsp = rsp;
   attr->rspm = rspm;
   return attr;
}

// category branch adopts attribute node
qaTree* adoptattr(qaTree* cat, qaNode* attr) {
   cat->children.push_back(attr);
   return cat;   
}

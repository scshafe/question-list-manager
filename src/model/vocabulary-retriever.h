#ifndef VOCABULARY_RETRIEVER_H
#define VOCABULARY_RETRIEVER_H

#include <iostream>

#include "vocab-item.h"

/*

----------This is an INTERFACE class

*/

class VocabularyRetriever
{
public:
  
  VocabularyRetriever();
  ~VocabularyRetriever();

public:

static VocabularyRetriever *p_inst;

  static VocabularyRetriever* get_instance(std::string filename = "/home/debian/vocabulary-words.json");


  virtual VocabItem get_vocab_item() = 0;

  
};


#endif

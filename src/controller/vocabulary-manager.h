#ifndef VOCABULARY_MANAGER_H
#define VOCABULARY_MANAGER_H

#include <vector>

#include "vocabulary-retriever.h"

class VocabularyManager
{
  static VocabularyManager* p_inst;
  std::vector<VocabItem> words;

  VocabularyManager();
  ~VocabularyManager();

public:
  static VocabularyManager* get_instance();
  
  VocabItem get_next_vocab_item();
  VocabItem get_prev_vocab_item();
};


#endif

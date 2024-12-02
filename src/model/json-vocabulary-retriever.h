#ifndef JSON_VOCABULARY_RETRIEVER_H
#define JSON_VOCABULARY_RETRIEVER_H

#include <string>
#include <vector>

#include "vocabulary-retriever.h"

class JsonVocabularyRetriever : public VocabularyRetriever
{
  std::vector<VocabItem> vocab_words;

  void initialize_vocab(std::string filename);

public:
  JsonVocabularyRetriever();
  JsonVocabularyRetriever(std::string filename);
  ~JsonVocabularyRetriever();

  virtual VocabItem get_vocab_item();
};


#endif

#ifndef JSON_VOCABULARY_RETRIEVER_H
#define JSON_VOCABULARY_RETRIEVER_H

#include <string>
#include <vector>
#include <json/json.h>

#include "vocabulary-retriever.h"

class JsonVocabularyRetriever : public VocabularyRetriever
{
  Json::Value root;
  std::vector<int> vocab_word_indices;

  void initialize_vocab(std::string filename);

public:
  JsonVocabularyRetriever();
  JsonVocabularyRetriever(std::string filename);
  ~JsonVocabularyRetriever();

  virtual VocabItem get_vocab_item();
};


#endif

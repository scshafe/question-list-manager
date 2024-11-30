#include <string>
#include <vector>
#include <fstream>
#include <json/json.h>

#include "vocabulary-retriever.h"
#include "json-vocabulary-retriever.h"


JsonVocabularyRetriever::JsonVocabularyRetriever()
{
  std::string filename = "/home/debian/vocabulary-words.json";
  
  initialize_vocab(filename);

  
}

JsonVocabularyRetriever::JsonVocabularyRetriever(std::string filename)
{
  initialize_vocab(filename);
}

JsonVocabularyRetriever::~JsonVocabularyRetriever()
{

}

VocabItem JsonVocabularyRetriever::get_vocab_item()
{

}

void JsonVocabularyRetriever::initialize_vocab(std::string filename)
{
  std::ifstream in(filename);
  std::string rawJson;
  std::string line;


  while(getline(in, line))
  {
    rawJson += line;
  }

  std::cout << rawJson << std::endl;
  in.close();


  Json::CharReaderBuilder builder;
  Json::Value root;
  JSONCPP_STRING err;
}
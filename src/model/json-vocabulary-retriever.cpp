#include <string>
#include <vector>
#include <fstream>
#include <json/json.h>

// for shuffling the word order
#include <algorithm>
#include <random>

#include "vocabulary-retriever.h"
#include "json-vocabulary-retriever.h"
#include "../libs/my-json-helper.h"


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


void JsonVocabularyRetriever::initialize_vocab(std::string filename)
{
  std::cout << "Initialzing json vocab from: " << filename << std::endl;

  std::ifstream in(filename);
  std::string rawJson;
  std::string line;


  while(getline(in, line))
  {
    rawJson += line;
  }

  std::cout << rawJson << std::endl;
  in.close();


  
  if (!MyJsonHelper::build_json_root(root, rawJson))
  {
    std::cerr << "Error Initializing vocab retriever" << std::endl;
    return;
  }

  int list_length = root["word_list"].size();

  for (int i = 0; i < list_length; i++)
  {
    vocab_word_indices.emplace_back(i);
  }

  auto rng = std::default_random_engine {};
  std::shuffle(std::begin(vocab_word_indices), std::end(vocab_word_indices), rng);

  for (int i = 0; i < list_length; i++)
  {
    std::cout << vocab_word_indices[i] << " ";
  }
  std::cout << std::endl;
}

VocabItem JsonVocabularyRetriever::get_vocab_item()
{
  int next_index = vocab_word_indices.front();
  vocab_word_indices.erase(vocab_word_indices.begin());

  VocabItem vocab_item;
  vocab_item.word = root["word_list"][next_index]["word"].asString();
  if (root["word_list"][next_index].isMember("definition"))
  {
    vocab_item.definition = root["word_list"][next_index]["definition"].asString();
  }
  return vocab_item;
}
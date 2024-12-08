#ifndef GROQ_SENTENCE_FETCHER_H
#define GROQ_SENTENCE_FETCHER_H

#include <string>


#include "sentence-fetcher.h"

class GroqSentenceFetcher : public SentenceFetcher
{
public:
  std::string curl_url;
  std::string model_type;
  std::string groq_api_authorization;

  GroqSentenceFetcher();
  ~GroqSentenceFetcher();

public:
  virtual std::string get_sentence(std::string word);
  std::string buildJsonPostData(std::string word);
};


#endif
#ifndef SENTENCE_FETCHER_H
#define SENTENCE_FETCHER_H

#include <string>

class SentenceFetcher
{
  static SentenceFetcher* p_inst;
public:
  SentenceFetcher();
  ~SentenceFetcher();

public:
  static SentenceFetcher* get_instance();

  virtual std::string get_sentence(std::string word) = 0;

};


#endif 

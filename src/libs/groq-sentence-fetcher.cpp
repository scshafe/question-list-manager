
#include <iostream>
#include <string>
#include <sstream>
#include <curl/curl.h>
#include <json/json.h>


#include "groq-sentence-fetcher.h"
#include "../libs/my-json-helper.h"

// GroqSentenceFetcher::GroqSentenceFetcher()
// {
//   // Should never be called
// }

GroqSentenceFetcher::GroqSentenceFetcher()
{
  curl_url = "https://api.groq.com/openai/v1/chat/completions";
  model_type = "llama3-8b-8192";

  std::stringstream ss;
  ss << "Authorization: Bearer " << getenv("GROQ_API_KEY");
  groq_api_authorization = ss.str();
  
}



/*
An example curl method using the commandline as outlined in Groq's documentation:

curl https://api.groq.com/openai/v1/chat/completions -s -H "Content-Type: application/json" -H "Authorization: Bearer $GROQ_API_KEY" -d '{
"model": "llama3-8b-8192",
"messages": [{
    "role": "user",
    "content": "use erudite in a sentence and nothing else. Do not include pleasantries"
}]
}'
*/

size_t WriteCallbackGroq(char *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

std::string GroqSentenceFetcher::buildJsonPostData(std::string word)
{
  std::stringstream ss;
  ss << "use " << word << " in a sentence and nothing else. Do not include pleasantries";
  std::string ai_query = ss.str();


  Json::Value root;

  root["model"] = model_type;

  Json::Value messages(Json::arrayValue);
  
  Json::Value nested_messages;
  nested_messages["role"] = "user";
  nested_messages["content"] = ai_query;

  messages.append(nested_messages);
  root["messages"] = messages;

  Json::StreamWriterBuilder writer;
  std::string output = Json::writeString(writer, root);

  return output;
}


std::string GroqSentenceFetcher::get_sentence(std::string word)
{
  std::cout << "Fetching Sentence for: " << word << std::endl;

  CURL *easy_handle;
  CURLcode res;

  std::string rawJson;

  easy_handle = curl_easy_init();
  if (easy_handle)
  {
    curl_easy_setopt(easy_handle, CURLOPT_URL, curl_url.c_str());
    curl_easy_setopt(easy_handle, CURLOPT_WRITEFUNCTION, WriteCallbackGroq);
    curl_easy_setopt(easy_handle, CURLOPT_WRITEDATA, &rawJson);

    curl_easy_setopt(easy_handle, CURLOPT_POST, 1);
    std::string data = buildJsonPostData(word);
    curl_easy_setopt(easy_handle, CURLOPT_POSTFIELDS, data.c_str());

    struct curl_slist *list;
    list = curl_slist_append(NULL, "Content-Type: application/json");
    list = curl_slist_append(list, groq_api_authorization.c_str());

    curl_easy_setopt(easy_handle, CURLOPT_HTTPHEADER, list);

    res = curl_easy_perform(easy_handle);

    curl_slist_free_all(list);
    curl_easy_cleanup(easy_handle);

  }
  else
  {
    std::cerr << "Error: invalid easy_handle for fetching example sentence" << std::endl;
    return "Error";
  }

  Json::Value root;
  if (!MyJsonHelper::build_json_root(root, rawJson))
  {
    return "Error fetching";
  }

  std::string output = root["choices"][0]["message"]["content"].asString();
  std::cout << output << std::endl;
  return output;
}

/*
Example Response from Groq API:

{
  "id": "chatcmpl-fa5fea3e-61b8-4c13-88f4-c28808b5e87e",
  "object": "chat.completion",
  "created": 1732990815,
  "model": "llama3-8b-8192",
  "choices": [
    {
      "index": 0,
      "message": {
        "role": "assistant",
        "content": "The historian's erudite analysis of the ancient text revealed a previously unnoticed pattern of linguistic influences."
      },
      "logprobs": null,
      "finish_reason": "stop"
    }
  ],
  "usage": {
    "queue_time": 0.010733388,
    "prompt_tokens": 27,
    "prompt_time": 0.00365065,
    "completion_tokens": 21,
    "completion_time": 0.0175,
    "total_tokens": 48,
    "total_time": 0.02115065
  },
  "system_fingerprint": "fp_a97cfe35ae",
  "x_groq": {
    "id": "req_01jdz4tk23epz8mzdz2ep46gjg"
  }
}
*/
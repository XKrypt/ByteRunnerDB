using System;
using Runner;
using Newtonsoft.Json.Linq;
using Newtonsoft.Json;

namespace Runner
{
    public class Doc
    {
        string rawData;

        string id;
        string storage;
        JObject doc;
        bool isJsonObject;

        public void Parse()
        {
            if (rawData == null || rawData.Length == 0) return;
            try
            {
                doc = JObject.Parse(rawData);
                isJsonObject = true;
            }
            catch (System.Exception)
            {
                isJsonObject = true;
            }

        }


    }
}
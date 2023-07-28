using System;
using Newtonsoft.Json.Linq;
using Runner;

namespace Runner
{
    public class BehaviourOperationResult
    {
        public bool blockOperation;

        public JObject additionalJsonData;

        public string additionalMessage;
        public string operationBlockReason;
    }
}
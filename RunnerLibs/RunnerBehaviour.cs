using System.Runtime.CompilerServices;


namespace Runner
{
    public class RunnerBehaviour
    {

        /// <summary>
        /// Disconnect client without reason
        /// </summary>
        /// <param name="id"></param>
        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        public extern static void DisconnectClient(int id, string reason);


        /// <summary>
        /// Send message to client
        /// obs: the message will go inside a json string.
        /// </summary>
        /// <param name="id">The client id</param>
        /// <param name="message">The message</param>
        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        public extern static void Send(int id, string message);
    }

}
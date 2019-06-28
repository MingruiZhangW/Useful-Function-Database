# What is a SIP Proxy Server?

> A SIP Proxy, also called a SIP Server, or even a SIP Proxy Server, facilitates communications between two SIP addresses. In practical terms, any SIP device can talk to another SIP device. But in order to that, they use a go-between, called a SIP proxy, to begin the communication, which then drops out, allowing point-to-point communication.

A SIP proxy is configured to do the tasks associated with finding the proper destination of a call. When an IP phone makes a call, it’s sending an invite request to a proxy server. The phone itself doesn’t know that the digits mean, but the proxy server does. The proxy server routes the request within the network, to a remote proxy server, or to an “off-domain network,” such as the PSTN.

A proxy server also handles call rules such as find me/follow me. The SIP proxy server is configured to have multiple phones ring simultaneously, or sequentially, and for how long before going to another destination, such as another extension or a voice mail box.

The SIP proxy server also handles security. If a call is being made to the PSTN network, an international destination, or any destination that costs money, the proxy server checks the caller’s identity and credit. The proxy server can check the caller’s identity to make sure the originating caller is not trying to impersonate a valid user, but if a valid user has his identity stolen, the SIP proxy will perceive the identity as valid and continue the call.

A  SIP Proxy Server has two modes of operation: “transaction stateful” and “transaction stateless.” A “stateless” proxy forgets the information about a request—the transaction—as soon as it is made. A “stateful” proxy remembers the entire transaction until the transaction is complete, at which point it becomes stateless again. A stateful proxy is able to handle SIP forking, day/night mode, and other complicated call rules because it can remember all of the incoming and outgoing transactions.

A SIP proxy server works alongside a registrar server and a redirect server. The registrar server has all the personal information about a user agent, such as their phone number. A redirect server collects information about the off-domain user, and then sends that information back to the proxy server, which can then send out the proper request.

# SIP Voice Mail

https://andrewjprokop.wordpress.com/2014/03/11/thank-you-for-calling-voicemail-and-sip/

# SIP MWI

https://www.myvoipapp.com/docs/mss_services/voice_mail/index.html

# Voice-Message

https://tools.ietf.org/html/rfc3842

```
 In some cases, detailed message summaries are not available.  The
   status line allows messaging systems or messaging gateways to provide
   the traditional boolean message waiting notification.

      Messages-Waiting: yes

   If the Request-URI or To header in a message-summary subscription
   corresponds to a group or collection of individual messaging
   accounts, the notifier MUST specify to which account the message-
   summary body corresponds.  Note that the account URI MUST NOT be
   delimited with angle brackets ("<" and ">").

      Message-Account: sip:alice@example.com

   In the example that follows, more than boolean message summary
   information is available to the User Agent.  There are two new and
   four old fax messages.

      Fax-Message: 2/4

   After the summary, the format can optionally list a summary count of
   urgent messages.  In the next example there are one new and three old
   voice messages, none of the new messages are urgent, but one of the
   old messages is.  All counters have a maximum value of 4,294,967,295
   ((2^32) - 1).  Notifiers MUST NOT generate a request with a larger
   value.  Subscribers MUST treat a larger value as 2^32-1.

      Voice-Message: 1/3 (0/1)
```

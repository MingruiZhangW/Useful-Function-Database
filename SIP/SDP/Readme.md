# SDP Knowledge

[The Offer/Answer Model](https://www.tutorialspoint.com/session_initiation_protocol/session_initiation_protocol_the_offer_answer_model)<br>
[SDP - Session Description Protocal - part one](https://www.3cx.com/blog/voip-howto/sdp-voip/)<br>
[SDP - Session Description Protocal - part two](https://www.3cx.com/blog/voip-howto/sdp-voip2/)<br>

### Example

    For Example

    The following is an example of an actual SDP message.

    v=0

    o=Andrew 2890844526 2890844526 IN IP4 10.120.42.3

    s= SDP Blog

    c=IN IP4 10.120.42.3

    t=0 0

    m=audio 49170 RTP/AVP 0 8 97

    a=rtpmap:0 PCMU/8000

    a=rtpmap:8 PCMA/8000

    a=rtpmap:97 iLBC/8000

    m=video 51372 RTP/AVP 31 32

    a=rtpmap:31 H261/90000

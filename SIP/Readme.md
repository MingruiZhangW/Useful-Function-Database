# SIP Knowledge

- [SIP INVITE header field](https://www.3cx.com/blog/voip-howto/sip-invite-header-fields/)
- [SIP Outbound Proxy](https://stackoverflow.com/questions/34195532/difference-between-sip-proxy-and-sip-outbound-proxy)
- [SIP Proxy](https://github.com/MingruiZhangW/Useful-Function-Database/blob/master/SIP/SIP_Proxy.md)
- [SIP Introduction - Slides](https://github.com/MingruiZhangW/Useful-Function-Database/blob/master/SIP/indroductiontosippublished-160410122633.pdf)
- [SIP Introduction - PDF](https://github.com/MingruiZhangW/Useful-Function-Database/blob/master/SIP/session_initiation_protocol_tutorial.pdf)
- [SIP Expert Web](https://andrewjprokop.wordpress.com/)
> [SIP Loop Detection](https://andrewjprokop.wordpress.com/2014/03/26/sip-loop-detection-will-it-go-round-in-circles/)<br>
> [SIP Authentication](https://andrewjprokop.wordpress.com/2015/01/27/understanding-sip-authentication/)
- [SDES](https://en.wikipedia.org/wiki/SDES)<br>
- [Annotated Example SDP for WebRTC](https://tools.ietf.org/id/draft-ietf-rtcweb-sdp-08.html#rfc.section.5.2.8)<br>
> [Blind Call Transfer & Attended Call Transfer](https://help.masierotechgroup.com/hc/en-us/articles/115013090548-What-is-the-difference-between-blind-and-attended-transfer-)<br>

- [SIP Voice-Mail, MWI(Message Waitting Indication)](https://github.com/MingruiZhangW/Useful-Function-Database/blob/master/SIP/sip_MWI.md)<br>

> **Print pjsip_msg**
```
char x[1024];
pjsip_msg_print(tdata->msg, x, 1024);
JAMI_ERR("Data: %s", x);
```

> **Differences Between SIP and SIPS** <br>
Ex: https://tools.ietf.org/id/draft-ietf-sip-sips-09.html#6.2<br>
Define: https://tools.ietf.org/html/rfc5630#section-3.3<br>
https://tools.ietf.org/html/rfc3261#section-19.1<br>
https://stackoverflow.com/questions/35129041/difference-between-sip-and-sips-uri

# Pjsip Implementation of SIPS Check<br>
https://trac.pjsip.org/repos/ticket/1735<br>
sip_inv.c(inv_check_secure_dlg())<br>
[Record Route](https://www.youtube.com/watch?v=p9OvtmTS-wU)

# Pjsip access sip display name
```
const auto sip_from_uri_name_address = reinterpret_cast<pjsip_name_addr*>(rdata->msg_info.from->uri);

std::string toDisplayName(sip_from_uri_name_address->display.ptr, sip_from_uri_name_address->display.slen);
```
# SIP re-INVITE
https://andrewjprokop.wordpress.com/2015/02/10/understanding-sip-re-invite/comment-page-1/
```
The most common use for re-INVITE is call hold. The party putting the call on hold sends a re-INVITE with SDP indicating that media will no longer be sent.
That same party will take the call off hold by sending another re-INVITE with SDP indicating that media transmission will resume
```

# ICE
[交互式连接建立](https://zhuanlan.zhihu.com/p/25087606)

# RTP/RTCP
```
The Real-time Transport Protocol (RTP) is a network protocol for delivering audio and video over IP networks.
RTP is used in communication and entertainment systems that involve streaming media, such as telephony,
video teleconference applications including WebRTC, television services and web-based push-to-talk features.

RTP typically runs over User Datagram Protocol (UDP).
RTP is used in conjunction with the RTP Control Protocol (RTCP). While RTP carries the media streams (e.g., audio and video),
RTCP is used to monitor transmission statistics and quality of service (QoS) and aids synchronization of multiple streams.
RTP is one of the technical foundations of Voice over IP and in this context is often used in conjunction with a
signaling protocol such as the Session Initiation Protocol (SIP) which establishes connections across the network.
```

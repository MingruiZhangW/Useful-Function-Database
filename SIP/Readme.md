# SIP Knowledge

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

# PJSIP Knowledge

- [PJSIP Developer Guide](https://github.com/MingruiZhangW/Useful-Function-Database/blob/master/SIP/PJSIP/PJSIP-Dev-Guide.pdf)<br>

- [Implementation Example - GB28181对接视频流](https://www.cnblogs.com/wanggang123/p/7507897.html)<br>

- SIP Message Header (Auth) Example

      Frame 992: 694 bytes on wire (5552 bits), 694 bytes captured (5552 bits) on interface 0
      Ethernet II, Src: LcfcHefe_da:bb:51 (54:e1:ad:da:bb:51), Dst: Cisco_39:96:40 (00:21:a1:39:96:40)
      Internet Protocol Version 4, Src: 192.168.50.194, Dst: 192.175.96.69
      User Datagram Protocol, Src Port: 59831, Dst Port: 5060
      Session Initiation Protocol (MESSAGE)
          Request-Line: MESSAGE sip:5145714228@montreal5.voip.ms SIP/2.0
              Method: MESSAGE
              Request-URI: sip:5145714228@montreal5.voip.ms
              [Resent Packet: False]
          Message Header
              Via: SIP/2.0/UDP 192.168.50.194:59831;branch=z9hG4bK.QQ2DfUVVD;rport
              From: "dlskdlskd" <sip:253902@montreal5.voip.ms>;tag=l4gb1wXcN
              To: sip:5145714228@montreal5.voip.ms
              CSeq: 21 MESSAGE
              Call-ID: qQeod~7aGc
              [Generated Call-ID: qQeod~7aGc]
              Max-Forwards: 70
              Supported: replaces, outbound
              Content-Type: text/plain
              Content-Length: 5
              Date: Thu, 11 Jul 2019 20:34:17 GMT
              User-Agent: LinphoneW10/3.12.0-273-g20efb4ad4 (belle-sip/1.6.3)
              Authorization:  Digest realm="montreal5.voip.ms", nonce="5da5d034", algorithm=MD5, username="253902", uri="sip:5145714228@montreal5.voip.ms", response="3d658fec59841ee17f02f0db85a05d73"
          Message Body
### Important!!!!!!!!!!!!!!!!!
> Request will get rejected if the CSeq is less than or equal to the CSeq in a previous request as they will get classified as re-transmits. So sometimes, Cseq number needs to be added manually. https://stackoverflow.com/questions/40533382/sip-dialog-cseq-sequence-number

### PJSIP Parse String to Sockaddr
> [pj_sockaddr_parse(family, 0, &pjstring, &addr)](https://www.pjsip.org/pjlib/docs/html/group__PJ__SOCK.htm#ga1562332273aa3900dc549cffd5b5c4e4)

### [PJSIP pjsip_inv_callback Structure](https://www.pjsip.org/pjsip/docs/html/structpjsip__inv__callback.htm)
    static const pjsip_inv_callback inv_cb = {
        invite_session_state_changed_cb,
        outgoing_request_forked_cb,
        transaction_state_changed_cb,
        sdp_request_offer_cb,
        nullptr /* on_rx_offer2 */,
        nullptr /* on_rx_reinvite */,
        sdp_create_offer_cb,
        sdp_media_update_cb,
        nullptr /* on_send_ack */,
        nullptr /* on_redirected */,
    };
  incoming request message will come from transaction_state_changed_cb<br>
  sdp_media_update_cb is called after SDP offer/answer session has completed.(also update SDP message)<br>
  **SDP attach with SIP INVITE**<br>

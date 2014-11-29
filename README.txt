AVR8 Winter Development Kit
    
Phiên bản: 1.0
Ngày cập nhật: 28/11/2014
Tác giả: Trần Tuân

Đã hoàn thiện:
- Phiên bản layout đầu tiên cho kit.
- Sử dụng chip ATmega8 để nạp chương trình.

Cần chỉnh sửa:
- Chỉnh sửa R của LED xanh < R của LED đỏ.
- Bỏ LED nguồn không cần thiết. Do LED mạch nạp luôn sáng.
- Đưa các header mạch, LED nạp sát lại gần nhau (2,54mm).
- Tìm hiểu nguyên nhân mạch chỉ nạp được ở tốc độ SLOW?

- Xem xét sử dụng cổng USB khác bền hơn.
- Xem xét việc thêm các R (điện trở) từ mạch nạp tới chip để đảm bảo an toàn.
- Xem xét việc thêm kết nối UART với máy tính.
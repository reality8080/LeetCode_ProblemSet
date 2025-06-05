# Mục Lục

- [**LeetCode Problem 1: Two Sum**](#leetcode-problem-1-two-sum)
  - [***Yêu Cầu Bài Toán***](#yêu-cầu-bài-toán)
  - [***Các Phương Pháp Giải Quyết***](#các-phương-pháp-giải-quyết)
    - [*1. Sử dụng `unordered_map` (Hash Table) - Phương Pháp Đề Xuất*](#1-sử-dụng-unordered_map-hash-table---phương-pháp-đề-xuất)
      - [Kiến Thức Nền Tảng: `unordered_map`](#kiến-thức-nền-tảng-unordered_map)
      - [Ý Tưởng Thuật Toán](#ý-tưởng-thuật-toán)
      - [Các bước thực hiện](#các-bước-thực-hiện)
      - [Ví dụ minh họa](#ví-dụ-minh-họa)
    - [*2. Sử dụng Sắp xếp và Hai Con Trỏ*](#2-sử-dụng-sắp-xếp-và-hai-con-trỏ)
      - [Ý Tưởng Thuật Toán (Sắp xếp và Hai Con Trỏ)](#ý-tưởng-thuật-toán-sắp-xếp-và-hai-con-trỏ)
      - [Các bước thực hiện (Sắp xếp và Hai Con Trỏ)](#các-bước-thực-hiện-sắp-xếp-và-hai-con-trỏ)
      - [Ví dụ minh họa (Sắp xếp và Hai Con Trỏ)](#ví-dụ-minh-họa-sắp-xếp-và-hai-con-trỏ)
  - [***Đánh Giá Hiệu Suất***](#đánh-giá-hiệu-suất)
- [**LeetCode Problem 2: Add Two Numbers**](#leetcode-problem-2-add-two-numbers)
  - [***Yêu Cầu Bài Toán***](#yêu-cầu-bài-toán)
  - [***Phương Pháp Giải Quyết***](#phương-pháp-giải-quyết)
    - [*1. Sử dụng Danh sách liên kết và phép cộng tính tay*](#1-sử-dụng-danh-sách-liên-kết-và-phép-cộng-tính-tay)
      - [Kiến Thức Nền Tảng: LinkedList](#kiến-thức-nền-tảng-linkedlist)
      - [Ý Tưởng Thuật Toán (LinkedList và Phép Cộng)](#ý-tưởng-thuật-toán-linkedlist-và-phép-cộng)
      - [Các bước thực hiện (LinkedList và Phép Cộng)](#các-bước-thực-hiện-linkedlist-và-phép-cộng)
  - [***Đánh Giá Hiệu Suất***](#đánh-giá-hiệu-suất-)

# LeetCode Problem 1: Two Sum

## Yêu Cầu Bài Toán

Cho một mảng các số nguyên `nums` và một số nguyên `target`, hãy trả về **chỉ số (indices)** của hai số trong mảng sao cho tổng của chúng bằng `target`.

Bạn có thể giả định rằng mỗi đầu vào sẽ có **đúng một giải pháp**, và bạn **không được sử dụng cùng một phần tử hai lần**.

Bạn có thể trả về câu trả lời theo bất kỳ thứ tự nào.

**Ví dụ:**

* **Example 1:**
    * Input: `nums = [2,7,11,15]`, `target = 9`
    * Output: `[0,1]`
    * Explanation: Vì `nums[0] + nums[1] == 9`, chúng ta trả về `[0, 1]`.

* **Example 2:**
    * Input: `nums = [3,2,4]`, `target = 6`
    * Output: `[1,2]`

* **Example 3:**
    * Input: `nums = [3,3]`, `target = 6`
    * Output: `[0,1]`

**Ràng buộc (Constraints):**

* `2 <= nums.length <= 10^4`
* `-10^9 <= nums[i] <= 10^9`
* `-10^9 <= target <= 10^9`
* Chỉ có một câu trả lời hợp lệ tồn tại.

---
## Các Phương Pháp Giải Quyết

### 1. Sử dụng `unordered_map` (Hash Table) - Phương Pháp Đề Xuất

#### Kiến Thức Nền Tảng: `unordered_map`

`std::unordered_map` trong C++ (tương đương với Hash Table) là một cấu trúc dữ liệu అసోసియేటివ్ container lưu trữ các cặp **(Key, Value)**. Nó cho phép truy cập các phần tử một cách nhanh chóng (thời gian trung bình là hằng số) dựa trên Key.

* **Cơ chế hoạt động cơ bản:**
    1.  **Băm Key:** Key đầu vào được xử lý bởi một hàm băm (hash function) để tạo ra một giá trị băm (hash value).
    2.  **Ánh xạ tới Bucket:** Giá trị băm này được ánh xạ thành một chỉ số (index), xác định một "bucket slot" trong một mảng nội bộ.
    3.  **Lưu trữ và Xử lý Xung đột:** Cặp `(Key, Value)` được lưu trữ liên quan đến bucket slot này. Nếu nhiều Key khác nhau cùng băm vào một bucket slot (xung đột), `std::unordered_map` thường sử dụng kỹ thuật **Nối kết riêng (Separate Chaining)**. Tức là, mỗi bucket slot sẽ trỏ đến đầu của một danh sách liên kết, nơi chứa tất cả các cặp `(Key, Value)` thuộc về bucket đó.
    4.  **Tìm kiếm:** Khi tìm kiếm, quá trình tương tự diễn ra để xác định bucket slot. Sau đó, nếu có danh sách liên kết, hệ thống sẽ duyệt qua danh sách đó để tìm Key chính xác.

* **Các phương thức thường dùng cho bài toán này:**
    * `map[key] = value` hoặc `insert({key, value})`: Thêm/cập nhật cặp key-value.
    * `find(key)`: Tìm kiếm key, trả về iterator.
    * `count(key)`: Kiểm tra sự tồn tại của key.

#### Ý Tưởng Thuật Toán

Sử dụng `std::unordered_map` để lưu trữ các số đã duyệt qua và chỉ số của chúng, giúp tìm "phần bù" một cách nhanh chóng.

**Các bước thực hiện:**

1.  **Khởi tạo:** Tạo một `std::unordered_map<int, int>` tên là `num_map` (Key: giá trị số, Value: chỉ số).
2.  **Duyệt mảng và Tìm kiếm/Lưu trữ:**
    * Lặp qua từng phần tử `nums[i]` với chỉ số `i`:
        * Tính "phần bù": `complement = target - nums[i]`.
        * **Kiểm tra `num_map`:** Nếu `complement` tồn tại như một key trong `num_map`:
            * Đã tìm thấy cặp: số `complement` (có chỉ số là `num_map[complement]`) và số `nums[i]` (có chỉ số `i`).
            * Trả về `{num_map[complement], i}`.
        * **Nếu không tồn tại:** Thêm `(nums[i], i)` vào `num_map` để các phần tử sau có thể tìm thấy nó.

**Ví dụ minh họa với `nums = [2,7,11,15]`, `target = 9`:**

1.  `num_map = {}`
2.  `i = 0, nums[0] = 2`. `complement = 9 - 2 = 7`.
    * `7` không có trong `num_map`.
    * Thêm `(2, 0)` vào `num_map`. `num_map = {2: 0}`.
3.  `i = 1, nums[1] = 7`. `complement = 9 - 7 = 2`.
    * `2` có trong `num_map`! `num_map[2]` là `0`.
    * Trả về `{0, 1}`.

---
### 2. Sử dụng Sắp xếp và Hai Con Trỏ

#### Ý Tưởng Thuật Toán

Phương pháp này yêu cầu sắp xếp mảng trước, sau đó sử dụng hai con trỏ di chuyển từ hai đầu mảng vào giữa để tìm cặp số có tổng bằng `target`. **Lưu ý quan trọng:** Vì bài toán yêu cầu chỉ số gốc, việc sắp xếp mảng `nums` trực tiếp sẽ làm mất thông tin này. Do đó, cần một bước chuẩn bị để lưu cả giá trị và chỉ số gốc.

**Các bước thực hiện:**

1.  **Chuẩn bị dữ liệu:**
    * Tạo một vector các cặp `(value, original_index)` từ mảng `nums` ban đầu.
    * Ví dụ: `nums = [3,2,4]` -> `indexed_nums = [(3,0), (2,1), (4,2)]`.

2.  **Sắp xếp:**
    * Sắp xếp `indexed_nums` dựa trên `value`.
    * Ví dụ: `indexed_nums = [(2,1), (3,0), (4,2)]`.

3.  **Khởi tạo Hai Con Trỏ:**
    * `left = 0` (trỏ đến đầu `indexed_nums`).
    * `right = n - 1` (trỏ đến cuối `indexed_nums`, với `n` là số phần tử).

4.  **Duyệt và tìm kiếm:**
    * Trong khi `left < right`:
        * Tính tổng hiện tại: `current_sum = indexed_nums[left].value + indexed_nums[right].value`.
        * **So sánh `current_sum` với `target`:**
            * Nếu `current_sum == target`: Đã tìm thấy! Trả về `{indexed_nums[left].original_index, indexed_nums[right].original_index}`.
            * Nếu `current_sum < target`: Tổng quá nhỏ, cần tăng giá trị. Di chuyển `left++`.
            * Nếu `current_sum > target`: Tổng quá lớn, cần giảm giá trị. Di chuyển `right--`.

**Ví dụ minh họa với `nums = [3,2,4]`, `target = 6`:**

1.  `indexed_nums = [(3,0), (2,1), (4,2)]`.
2.  Sắp xếp: `indexed_nums = [(2,1), (3,0), (4,2)]`.
3.  `left = 0` (trỏ tới `(2,1)`), `right = 2` (trỏ tới `(4,2)`).
4.  Vòng lặp:
    * `current_sum = 2 + 4 = 6`.
    * `current_sum == target`. Trả về `{1, 2}`.

---
## Đánh Giá Hiệu Suất

| Phương Pháp             | Độ Phức Tạp Thời Gian | Độ Phức Tạp Không Gian | Ghi Chú                                                                                                                                |
| :----------------------- | :-------------------- | :--------------------- | :------------------------------------------------------------------------------------------------------------------------------------- |
| Brute Force              | $O(N^2)$              | $O(1)$                 | Duyệt qua tất cả các cặp số.                                                                                                           |
| **Hash Table (Đề xuất)** | $O(N)$                | $O(N)$                 | Duyệt mảng một lần. Thao tác với hash table (thêm, tìm) là $O(1)$ trung bình. Không gian để lưu trữ tối đa $N$ phần tử trong hash table. |
| Sắp xếp + Hai con trỏ    | $O(N \log N)$         | $O(N)$                 | Sắp xếp tốn $O(N \log N)$. Duyệt hai con trỏ tốn $O(N)$. Không gian $O(N)$ để lưu các cặp (giá trị, chỉ số gốc) nếu cần chỉ số gốc.  |

*Trong đó N là số lượng phần tử trong mảng `nums`.*

---
# LeetCode Problem 2: Add Two Numbers

## Yêu Cầu Bài Toán 

Bạn được cung cấp hai danh sách liên kết không rỗng biểu diễn hai số nguyên không âm. Các chữ số được lưu trữ theo **thứ tự ngược lại** và mỗi nút của chúng chứa một chữ số duy nhất. Cộng hai số và trả về tổng dưới dạng danh sách liên kết.

Bạn có thể cho rằng hai số không chứa bất kỳ số 0 nào đứng đầu, ngoại trừ chính số 0.

**Ví dụ 1:**

* **Input:** `l1 = [2,4,3]`, `l2 = [5,6,4]`
* **Output:** `[7,0,8]`
* **Giải thích:** $342 + 465 = 807$.

**Ví dụ 2:**

* **Input:** `l1 = [0]`, `l2 = [0]`
* **Output:** `[0]`

**Ví dụ 3:**

* **Input:** `l1 = [9,9,9,9,9,9,9]`, `l2 = [9,9,9,9]`
* **Output:** `[8,9,9,9,0,0,0,1]`

**Ràng buộc:**

* Số lượng nút trong mỗi danh sách liên kết nằm trong phạm vi `[1, 100]`.
* `0 <= Node.val <= 9`
* Đảm bảo rằng danh sách biểu diễn một số không có số 0 đứng đầu.

---

## Phương Pháp Giải Quyết 

### 1. Sử dụng Danh sách liên kết và phép cộng tính tay

#### Kiến Thức Nền Tảng: LinkedList

Danh sách liên kết (LinkedList) là một cấu trúc dữ liệu tuyến tính bao gồm một chuỗi các **nút (nodes)**.
Mỗi nút chứa hai phần:
1.  **Dữ liệu (Value):** Giá trị mà nút đó lưu trữ.
2.  **Con trỏ Tiếp theo (Next pointer):** Một con trỏ trỏ đến nút kế tiếp trong danh sách. Nút cuối cùng sẽ có con trỏ tiếp theo là `nullptr` (hoặc `null`).

#### Ý Tưởng Thuật Toán (LinkedList và Phép Cộng)

Bài toán yêu cầu cộng hai số được biểu diễn bởi danh sách liên kết, trong đó các chữ số được lưu trữ theo thứ tự ngược (chữ số hàng đơn vị ở đầu danh sách). Chúng ta sẽ mô phỏng phép cộng bằng tay, duyệt qua cả hai danh sách từ đầu đến cuối, cộng các chữ số tương ứng cùng với một giá trị **nhớ (carry)** từ phép cộng trước đó.

#### Các bước thực hiện (LinkedList và Phép Cộng)

1.  **Khởi tạo:**
    * Khởi tạo `carry = 0` để lưu trữ phần nhớ của phép cộng.
    * Khởi tạo hai con trỏ `curr1` và `curr2` trỏ lần lượt đến đầu danh sách `l1` và `l2`.

2.  **Duyệt và Cộng:**
    * Lặp trong khi `curr1` khác `nullptr` HOẶC `curr2` khác `nullptr` HOẶC `carry` khác `0`.
    * Lấy giá trị từ nút hiện tại của `l1` (gọi là `x`). Nếu `curr1` là `nullptr`, coi `x = 0`. Di chuyển `curr1` đến nút tiếp theo.
    * Lấy giá trị từ nút hiện tại của `l2` (gọi là `y`). Nếu `curr2` là `nullptr`, coi `y = 0`. Di chuyển `curr2` đến nút tiếp theo.
    * Tính tổng: `sum = x + y + carry`.
    * Cập nhật `carry`: `carry = sum / 10` (phần nguyên của `sum` chia cho 10).
    * Tạo một nút mới với giá trị `sum % 10` (phần dư của `sum` chia cho 10, tức là chữ số hàng đơn vị của `sum`).
    * Kiểm tra độ dài của 2 danh sách và carry, nếu không bằng nhau thì sẽ thêm các số node có `value = 0`
    * Di chuyển `curr1` và `curr2` đến các `node` tiếp theo.

3.  **Kết quả:**
    * Sau vòng lặp, danh sách kết quả được lưu trên `l1`.

| Phương Pháp                                 | Độ Phức Tạp Thời Gian         | Độ Phức Tạp Không Gian        | Ghi Chú                                                                                                                                                                 |
| :------------------------------------------- | :---------------------------- | :---------------------------- | :---------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Danh sách liên kết và phép cộng tính tay** | $O(\max(M, N))$               | $O(\max(M, N))$               | Duyệt qua mỗi danh sách một lần. $M$ và $N$ là độ dài của hai danh sách liên kết. Không gian dùng để tạo danh sách kết quả, có độ dài tối đa là $\max(M, N) + 1$. |

*Trong đó M và N lần lượt là số lượng phần tử trong danh sách liên kết `l1` và `l2`.*
---
# LeetCode Problem 3: Longest Substring Without Repeating Characters

## Yêu Cầu Bài Toán

Cho một chuỗi s, hãy tìm độ dài của chuỗi con dài nhất không có ký tự trùng lặp.

Ví dụ 1:

Đầu vào: s = "abcabcbb"
Đầu ra: 3
Giải thích: Câu trả lời là "abc", có độ dài là 3.
Ví dụ 2:

Đầu vào: s = "bbbbb"
Đầu ra: 1
Giải thích: Câu trả lời là "b", có độ dài là 1.
Ví dụ 3:

Đầu vào: s = "pwwkew"
Đầu ra: 3
Giải thích: Câu trả lời là "wke", có độ dài là 3.
Lưu ý rằng câu trả lời phải là một chuỗi con, "pwke" là một chuỗi con chứ không phải là một chuỗi con.

Ràng buộc:

0 <= s.length <= 5 * 104
s bao gồm các chữ cái tiếng Anh, chữ số, ký hiệu và khoảng trắng.
---

# Phương Pháp Giải Quyết

## 1. Sử dụng Danh sách liên kết và phép cộng tính tay

### Kiến Thức Nền Tảng

* **String (Chuỗi kí tự):**
    * Khởi tạo và thao tác với `std::string`.
    * Các phương thức quan trọng: `size()`, `empty()`, `find()`, `+=` (nối chuỗi), `erase()`.
    * Hằng số `std::string::npos` (biểu thị không tìm thấy).

### Ý Tưởng Thuật Toán
Dùng **string** để tạo các chuỗi con sao cho mỗi chuỗi là dài nhất, liên tiếp và không bị trùng lặp.

### Các bước thực hiện
1.  **Khởi tạo** các biến cần thiết gồm có chuỗi string con, độ dài `maxlength`.
2.  Thực hiện **vòng lặp** duyệt qua tất cả các phần tử cho trước và tìm độ dài phù hợp nhất với yêu cầu (Thêm vòng lặp `for` để tìm).
3.  Nếu thấy các phần tử bị **trùng** thì quay trở lại.

---

## 2. Sử dụng hai con trỏ và cửa sổ trượt động

### Kiến Thức Nền Tảng
* **Hai con trỏ (Two Pointers) và Cửa sổ trượt động (Sliding Window):**
    * Kỹ thuật sử dụng hai con trỏ (`left`, `right`) để định nghĩa một "cửa sổ" trên một cấu trúc dữ liệu (ví dụ: chuỗi hoặc mảng).
    * Cửa sổ có thể mở rộng hoặc thu hẹp dựa trên các điều kiện của bài toán.

### Ý Tưởng Thuật Toán
Dùng **string** để tạo các chuỗi con sao cho mỗi chuỗi là dài nhất, liên tiếp và không bị trùng lặp.

### Các bước thực hiện
1.  **Khởi tạo** các biến cần thiết gồm có chuỗi string con, độ dài `maxlength` và 2 con trỏ `left` và `right`.
2.  Thực hiện **trượt cửa sổ động** trên mảng bằng cách:
    * Thêm các phần tử vào chuỗi con (tăng `right`, thêm phần tử vào chuỗi con ở vị trí mới trượt của con trỏ `right`).
    * Khi gặp phần tử **lặp lại** trong chuỗi thì giảm lại cho đến khi chuỗi không còn có các phần tử bị trùng (giảm `left`, bỏ các phần tử ở vị trí con trỏ `left`).
3.  **So sánh** số lượng phần tử con và tìm ra `max`.

| Tên Phương Pháp (từ code)                                  | Độ phức tạp thời gian | Độ phức tạp không gian | Mô tả / Ghi chú                                                                                                                                                             |
| :----------------------------------------------------------- | :-------------------: | :--------------------: | :-------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Cách 1: Đánh giá bằng `string`** |       $O(N^3)$        |        $O(N)$        | Duyệt qua tất cả các chuỗi con khả dĩ bắt đầu từ vị trí `i`. Xây dựng chuỗi con và kiểm tra sự lặp lại ký tự bằng `string::find()`.                                              |
| **Cách 2: "Quy Hoạch Động" (dùng `vector` và `string::find`)** |       $O(N^3)$        |        $O(N)$        | Tương tự Cách 1, nhưng lưu các độ dài vào một `vector` và sau đó sắp xếp để tìm giá trị lớn nhất. (Lưu ý: Code có dòng `a[i]+=a[j]` bất thường và có bình luận tự đánh giá thấp). |
| **Cách 3: Hai con trỏ (cửa sổ trượt dùng `string`)** |       $O(N^2)$        |        $O(N)$        | Sử dụng hai con trỏ `left` và `right` để tạo một cửa sổ trượt. Một chuỗi `s1` được dùng để lưu các ký tự trong cửa sổ hiện tại. Thao tác `find` và `erase` trên `s1` mất $O(L)$ (với $L$ là độ dài cửa sổ). |
| **(Tham khảo) Cách 3 Tối ưu: Hai con trỏ + Bảng băm** |        $O(N)$         |    $O(\min(N,k))$   | (Không có trong code đã cho, nhưng được gợi ý) Dùng hai con trỏ và bảng băm (hoặc mảng tần suất) để theo dõi ký tự trong cửa sổ. Thao tác kiểm tra/cập nhật ký tự trong bảng băm trung bình là $O(1)$. $k$ là kích thước của bộ ký tự. |
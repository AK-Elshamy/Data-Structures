# 📈 Time Complexity

## Asymptotic Complexity – Three Types

- 💡 **Best Case**: Omega Notation `Ω`
- 💡 **Average Case**: Theta Notation `Θ`
- 💡 **Worst Case**: Big O Notation `O`

---

## 🧠 خطوات حساب Time Complexity:

1. احسب عدد الخطوات لتكوين معادلة رياضية.
2. احذف جميع الثوابت والأرقام الصغيرة.
3. خذ أكبر أس (power) للمتغير `n` في حالة وجود متغير واحد.
4. إذا وُجد أكثر من متغير، نأخذ كل المتغيرات المؤثرة.

---

## 🏁 ترتيب تعقيد الوقت من الأفضل للأسوأ:

| التعقيد       | التقييم       | الوصف                                                |
|---------------|----------------|-------------------------------------------------------|
| `O(1)`        | ✅ ممتاز       | وقت ثابت، لا يتأثر بحجم البيانات.                     |
| `O(log n)`    | 👍 جيد جدًا    | نمو لوغاريتمي، فعال جدًا للبيانات الكبيرة.            |
| `O(n)`        | 🙂 متوسط       | نمو خطي، جيد للحجم المتوسط.                          |
| `O(n log n)`  | 😐 مقبول       | شائع في الخوارزميات الفعالة مثل Merge Sort.         |
| `O(n²)`       | ❌ ضعيف        | نمو تربيعي، بطيء جدًا مع البيانات الكبيرة.           |
| `O(2ⁿ)`       | 🚫 سيء جدًا     | نمو أُسي، غير عملي مع الحجم الكبير.                  |
| `O(n!)`       | 💀 كارثي        | نمو مضاعف، لا يُستخدم مع بيانات كبيرة إطلاقًا.       |

![Image 1](images/1.png)
![Image 2](images/2.png)
![Image 3](images/3.png)
![Image 4](images/4.png)
![Image 5](images/5.png)
![Image 6](images/6.png)
![Image 7](images/7.png)
![Image 8](images/8.png)
![Image 9](images/9.png)
![Image 10](images/10.png)
![Image 11](images/11.png)
![Image 12](images/12.png)
![Image 13](images/13.png)
![Image 14](images/14.png)

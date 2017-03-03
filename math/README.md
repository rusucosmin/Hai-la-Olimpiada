#Matematica pentru concursuri si alte smenuri

- [Concurs Prosoft 2017](http://www.infoarena.ro/prosoft-2017)
- [Cautarea ta binara este gresita](http://www.infoarena.ro/blog/cautare-binara)
- [Algoritmul lui Euclid](http://www.infoarena.ro/problema/euclid2)
- [Euclid explained](https://www.khanacademy.org/computing/computer-science/cryptography/modarithmetic/a/the-euclidean-algorithm)
- [Euclid extins](http://www.infoarena.ro/algoritmul-lui-euclid)
- Combinari, Aranajamente, Permutari
- [Invers Modular](http://www.infoarena.ro/problema/inversmodular)
- [KFib](http://www.infoarena.ro/problema/kfib)
- [Antobroasca](http://www.infoarena.ro/problema/antobroasca)


#Euclid proof

Let a, b be the input numbers.

If b|a then gcd(a, b) = b.
This is indeed so because no number (b, in particular) may have
a divisor greater than the number itself (I am talking here of non-negative integers.)

If a = bt + r, for integers t and r, then gcd(a, b) = gcd(b, r).
Indeed, every common divisor of a and b also divides r. Thus gcd(a, b) divides r.
But, of course, gcd(a, b)|b. Therefore, gcd(a, b) is a common divisor of b and r
and hence gcd(a, b) ≤ gcd(b, r). The reverse is also true because every divisor
of b and r also divides a.

d | b => b = k1 * d
d | r => r = k2 * d

a = bt + r = k1 * d * t + k2 * d = d * (k1 * t + k2) => d | a

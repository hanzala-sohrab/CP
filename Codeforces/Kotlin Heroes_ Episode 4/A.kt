import java.util.*
fun main(args: Array<String>) {
    val sc = Scanner(System.`in`)
    val t:Int = sc.nextInt()
    var c = 0
    while (c<t)
    {
        val n:Long = sc.nextLong()
        val k:Long = sc.nextLong()
        if (k > 1)
        {
            var s = (k*k*k*k - 1)/(k-1);
            var n1 = n / s;
            var n2 = k * n1;
            var n3 = k * n2;
            var n4 = k * n3;
            print(java.lang.String.format("%d %d %d %d\n",n1,n2,n3,n4))
        }
        else
        {
            var n1 = n / 4;
            var n2 = k * n1;
            var n3 = k * n2;
            var n4 = k * n3;
            print(java.lang.String.format("%d %d %d %d\n",n1,n2,n3,n4))
        }
        ++c
    }
}
import java.util.*
import kotlin.random.Random.Default.nextInt

fun main() {
    val sc = Scanner(System.`in`)
    var c = 0
//    val t:Int = Integer.valueOf(readLine())
    val t:Int = sc.nextInt()
    while (c < t)
    {
        val a:Int = sc.nextInt()
        val b:Int = sc.nextInt()
        println(a+b)
        ++c
    }
}
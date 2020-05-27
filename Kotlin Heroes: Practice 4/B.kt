import java.util.*
import kotlin.math.sqrt

fun main() {
    val sc = Scanner(System.`in`)
    val t:Int = sc.nextInt()
    var c = 0
    while (c < t)
    {
        val a1:Int = sc.nextInt()
        val b1:Int = sc.nextInt()
        val a2:Int = sc.nextInt()
        val b2:Int = sc.nextInt()
        if (a1 == a2)
            if (b1 + b2 == a1)
                println("Yes")
            else
                println("No")
        else if (a1 == b2)
            if (a2 + b1 == a1)
                println("Yes")
            else
                println("No")
        else if (a2 == b1)
            if (a1 + b2 == a2)
                println("Yes")
            else
                println("No")
        else if (b2 == b1)
            if (a1 + a2 == b2)
                println("Yes")
            else
                println("No")
        ++c
    }
}
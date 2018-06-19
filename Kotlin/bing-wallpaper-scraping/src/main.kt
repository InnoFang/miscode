import org.jsoup.Jsoup
import org.jsoup.nodes.Document
import org.jsoup.select.Elements
import java.io.File
import java.net.URL
import java.util.*
import kotlin.system.exitProcess

/**
 * Created with IntelliJ IDEA
 * Created By Inno Fang
 * Date: 2018/6/19
 * Time: 15:35
 * Third-party used: [JSoup](https://github.com/jhy/jsoup)
 */

val DIR = File("E:/bing/kt/")
val WALLPAPER_URL: (Int) -> String = { page -> "http://bing.plmeizi.com/?page=$page" }

fun crawl(pageNum: Int): List<String> {
    val imgUrls = mutableListOf<String>()
    (1..pageNum).forEach { page ->
        println("====== crawl page $page ======")
        val html: Document = Jsoup.connect(WALLPAPER_URL(page)).get()
        val item: Elements = html.getElementsByClass("item")
        item.forEach { item ->
            imgUrls.add(
                    item.getElementsByTag("div")[0]
                            .getElementsByTag("img")[0]
                            .attr("src")
                            .replace("jpg-listpic", "jpg")
            )
        }
    }
    return imgUrls
}

fun downloadBingWallpaper(imgUrls: List<String>) {
    val total = imgUrls.size
    println("====== Downloading, total $total wallpapers. ======")
    imgUrls.forEachIndexed { idx, url ->
        val filename = url.substring(url.lastIndexOf('/') + 1)
        val output = File(DIR, filename)
        val imgUrl = URL(url)
        output.writeBytes(imgUrl.readBytes())
        println("[${idx+1}/$total] Saved $filename")
    }
}

fun input(tips: String): Int {
    print(tips)
    val page = Scanner(System.`in`).nextInt()
    assert(page > 0)
    return page
}

fun main(args: Array<String>) {
    if (!DIR.exists() && !DIR.mkdir()) {
        println("""Create directory '$DIR' failed.""")
        exitProcess(0)
    }
    val imgUrls = crawl(input("How many pages of wallpaper do you want (9 items per page)? "))
    downloadBingWallpaper(imgUrls)
}
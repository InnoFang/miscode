package main

import (
	"time"
	"fmt"
	"math/rand"
)

func main() {
	// 1. 获取当前时间
	t1 := time.Now()
	fmt.Printf("%T\n", t1)
	fmt.Println(t1)

	// 2. 获取指定时间
	t2 := time.Date(2001, 4, 23, 12, 42, 15, 1111, time.Local)
	fmt.Println(t2)

	// 3. time --> string 之间的转换，即把其他时间格式转换成你需要的格式
	// 转换格式需要符合模板规则，e.g. 2006年1月2日 15:04:05
	// 年份2006，月份为1月，日期为2日，时间为下午15:04:05
	// 模板日期必须是固定的 06-1-2-3-4-5
	s1 := t1.Format("2006年1月2日 15:04:05")
	fmt.Println(s1)

	s2 := t2.Format("2006-1-2 15点04分")
	fmt.Println(s2)

	// 4. string -> time
	// time.Parse("模板", str) -> time, err
	// 模板格式需与时间字符串相匹配，否则无法解
	// 并且模板日期仍然是固定的 06-1-2-3-4-5
	s3 := "1999年12月30日"
	t3, err := time.Parse("2006年01月02日", s3)
	if err != nil {
		fmt.Println("err: ", err)
	}
	fmt.Println(t3)

	// 5. 根据当前时间，获取指定内容
	year, month, day := t1.Date()
	fmt.Println(year, month, day) // 年月日

	hour, min, sec := t1.Clock()
	fmt.Println(hour, min, sec)   // 时分秒

	fmt.Println(t1.YearDay())	// 日期为这一年的第几天
	fmt.Println("年：", t1.Year())		// 获取日期年份
	fmt.Println("月：", t1.Month())
	fmt.Println("日：", t1.Day())
	fmt.Println("时：", t1.Hour())
	fmt.Println("分：", t1.Minute())
	fmt.Println("秒：", t1.Second())
	fmt.Println("纳秒：", t1.Nanosecond())
	fmt.Println("星期：", t1.Weekday())

	// 6. 时间戳：指定日期，距离1970年1月1日0时0分0秒的时间差值：秒或纳秒
	fmt.Println(t1.Unix())		// 秒的差值
	fmt.Println(t1.UnixNano())	// 纳秒的差值

	// 7. 时间间隔
	t5 := t1.Add(time.Hour)
	fmt.Println(t1)
	fmt.Println(t5) // 比当前日期多1小时
	fmt.Println(t1.Add(24 * time.Hour)) // 比当前日期多1天

	t6 := t1.AddDate(1, 1, 1)
	fmt.Println(t6) // 比当前日期多1年1月1日

	d1 := t5.Sub(t1) // t5 与 t1 的时间间隔差一小时
	fmt.Println(d1)

	// 8. 睡眠
	// 随机[1-5]s睡眠时间
	rand.Seed(time.Now().UnixNano())
	randNum := rand.Intn(5) + 1
	fmt.Println("随机", randNum, "s")
	time.Sleep(time.Duration(randNum) * time.Second)
	fmt.Println("睡眠结束")

}

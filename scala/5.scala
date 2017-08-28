def passStudents(scores: Map[String, Map[String, Int]]):Map[String, Int] = {
	val result = collection.mutable.Map[String,Int]()
	for(
		v <- scores
	){ 
		for{
			math <- v._2.get("math")
			english <- v._2.get("english")
		}
		yield{
			result += v._1 -> (math+english)/2
		}
	}
	result.filter(_._2>=80).toMap
}

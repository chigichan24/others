class q1{
  def show(value: Option[String]):Unit = {
    val tmp = value.get
    println(tmp)
  }
}
obj = new q1()
obj.show(Some["Hello"])

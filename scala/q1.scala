class q1{
  def show(value: Option[String]):Unit = {
    if(value.isDefined){
    	println(value.get)
    }
  }
}
obj = new q1()
obj.show(Some["Hello"])

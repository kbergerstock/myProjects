# ruby program
# hello world
# k. r. bergerstock

class World

 attr_reader :name
	
	def initialize
		@mass = 1
		@name = "Terra"
	end	
	
	def title
		return "hello " + @name + " from ruby\n"
	end	

end

class User
	attr_reader :name
	
	def initialize
		@name = "Keith"
	end		
end


w = World.new
u = User.new

puts w.title
puts "good bye "+u.name

$stdin.gets


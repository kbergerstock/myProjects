# ruby program - shell
# k. r. bergerstock

class World

	def initialize
		puts "hello new world"
	end
	
	def goodby
		puts "goodby cruel world"
	end
end

class MAIN

	attr_reader :world
	
	def initialize
		puts "Ruby Shell"	
		puts "K. R. Bergerstock"
		@world = World.new
	end	

	def run
		# add commands here
		world.goodby
	end			

end

main = MAIN.new
main.run

$stdin.gets
# ruby program - hat benchmark implemented in ruby
# k. r. bergerstock

class Rhat

	private
		def calcCy
			return 0
		end
		
		def calcCx
			return 0
		end
		
	public
		def draw
			puts " draw routine"
		end
end


class MAIN

 	attr_reader :hat
 	
	def initialize
		puts "Ruby hat"	
		puts "K. R. Bergerstock"
		hat = Rhat.new
	end	

	def run
		# add commands here
		hat.draw
	end			

end

main = MAIN.new
main.run

$stdin.gets
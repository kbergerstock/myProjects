# ruby program - hat benchmark implemented in ruby
# k. r. bergerstock

require "opengl"
require "glut"

class GLUT_SHELL

 	attr_reader :width, :height, :name
 	
	def initialize(width,height,name)
		@name = name
		@width = width
		@height = height	
	
		GLUT.Init
	   	GLUT.InitDisplayMode(GLUT::SINGLE | GLUT::RGB)
	   	GLUT.InitWindowSize(@width, @height)
	   	GLUT.InitWindowPosition(100, 100)
	   	GLUT.CreateWindow(@name)
	end
	
	def init
	   GL.ClearColor(0.0, 0.0, 0.0, 0.0);
	
	   GL.MatrixMode(GL::PROJECTION);
	   GL.LoadIdentity();
	   GL.Ortho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);	
	end
	
	def box_shape
      GL.Clear (GL::COLOR_BUFFER_BIT);
	
	   GL.Color(1.0, 1.0, 1.0);
	   GL.Begin(GL::POLYGON);
	      GL.Vertex(0.25, 0.25, 0.0);
	      GL.Vertex(0.75, 0.25, 0.0);
	      GL.Vertex(0.75, 0.75, 0.0);
	      GL.Vertex(0.25, 0.75, 0.0);
	   GL.End();
	end
	
	def points
		GL.Clear (GL::COLOR_BUFFER_BIT);	
		GL::PointSize(1.0);
   		GL::Color(1.0, 1.0, 0.0);
   		GL::Begin(GL::POINTS);
	      GL.Vertex(0.25, 0.25, 0.0);
	      GL.Vertex(0.75, 0.25, 0.0);
	      GL.Vertex(0.75, 0.75, 0.0);
	      GL.Vertex(0.25, 0.75, 0.0);   		
		GL::End();		
	end

	def draw_point(sx,sy)
		gx = sx / @width;
		gy = sy / @height;
		GL.Vertex(gx,gy,0.0)
	end
		
	def draw
		box_shape();
	end
	
	def display

	   draw();
	
	   GL.Flush();	
	end 
	   	
			
	def run
		# add commands here
		init();
        GLUT.DisplayFunc(display); 
 		GLUT.MainLoop()
	end			

end

class Rhat < GLUT_SHELL

	attr_reader :m_pi, :xp, :yp , :zp, :xr, :yr
 
	def initialize(width,height,name)
		super(width,height,name);
		@m_pi =  3.14159265358979323846
		@xp = 300.0
		@yp = 110.0
		@zp = 90.0
		@xr = 1.5 * @m_pi
		@yr = 1.0

	end	
  
	def draw
		xf  = @xr/@xp;
		yf  = @yp/@yr;
		zf  = @xp/@zp;	
		xp2 = @xp * @xp;
		
		cx = @width / 2.0;
		cy = ((@height / 2.0) * 9.0 ) / 10.0;		
		
		GL.Clear (GL::COLOR_BUFFER_BIT);	
		GL::PointSize(1.0);
   		GL::Color(1.0, 2.0, 0.0);
   		GL::Begin(GL::POINTS);
   		
	    zi = -cx;	  
	    xi = nil;
	    
		while zi < cx
			if (zi > -@zp) && (zi < @zp)
				zt = zf * zi;
				xl = 0.5 + Math.sqrt(xp2 - (zt * zt));
		
				xi = -xl;
				while xi <= xl
					xt = Math.sqrt(xi * xi + zt*zt) * xf;
				    yy =  Math.sin( Math.sin(xt) + 0.4 * Math.sin(3.0 * xt) ) * yf;
				    sx = xi + zi + cx;
				    sy = @height - (zi + cy - yy);
					draw_point(sx,sy);				    
					xi = xi + 2.0;
				end			 				
			end
			zi = zi + 1.0;
		end		  			  		  
		GL::End();			
	end
	
end

main = Rhat.new(800.0,600.0,"T-HAT");
main.run



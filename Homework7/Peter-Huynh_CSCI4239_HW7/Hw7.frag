/* ******************************
 *  Name:       Peter Tran Huynh
 *  Title:      HW7 - Image Processing
 *  Course:     CSCI 4239
 *  Semester:   Spring 2017
 *  File Notes:
 *    Fragment Shader - Inter-image processing
 ***************************** */
uniform int       mode;
uniform float     frac;
uniform sampler2D img0;
uniform sampler2D img1;

void main()
{
   vec4 pix0 = texture2D(img0,gl_TexCoord[0].st);
   vec4 pix1 = texture2D(img1,gl_TexCoord[0].st);
   //  First image
   if (mode==0)
      gl_FragColor = pix0;
   //  Second image
   else if (mode==1)
      gl_FragColor = pix1;
   //  Transition
   else if (mode==2)
      gl_FragColor = mix(pix0,pix1,frac);
   //  Pixelate
   else if (mode == 3 || mode == 4)
   {
      if (frac == 0.00 && mode == 3)      gl_FragColor = pix0;
	  else if (frac == 0.00 && mode == 4) gl_FragColor = pix1;
      else
      {
         //  Scaling down frac for less intense pixelation
         float scale     = frac * 0.03;
         //  Intentionally making x and y values less accurate for pixelation effect
         float estimateX = scale * floor(gl_TexCoord[0].x / scale);
         float estimateY = scale * floor(gl_TexCoord[0].y / scale);
         if (mode == 3) gl_FragColor = texture2D(img0, vec2(estimateX, estimateY));
		 if (mode == 4) gl_FragColor = texture2D(img1, vec2(estimateX, estimateY));
      }
   }
   //  Swapping RGB values
   else if (mode == 5)
      gl_FragColor = vec4(pix1[0], pix0[1], pix0[2], pix0[3]);
   else if (mode == 6)
      gl_FragColor = vec4(pix0[0], pix1[1], pix0[2], pix0[3]);
   else if (mode == 7)
      gl_FragColor = vec4(pix0[0], pix0[1], pix1[2], pix0[3]);
   //  Inverse Color
   else if (mode == 8)
	  gl_FragColor = vec4(abs(pix1[0] - frac), abs(pix1[1] - frac), abs(pix1[2] - frac), pix1[3]);
   else
      discard;
}

/*
 * This confidential and proprietary software may be used only as
 * authorised by a licensing agreement from ARM Limited
 * (C) COPYRIGHT 2001-2002, 2007-2010 ARM Limited
 * ALL RIGHTS RESERVED
 * The entire notice above must be reproduced on all authorised
 * copies and copies may only be made to the extent permitted
 * by a licensing agreement from ARM Limited.
 */

#ifdef GL_ES
precision mediump float;
#endif

varying vec4 texcoord0;
uniform samplerCube cube;

void main()
{
	gl_FragColor = textureCube(cube, texcoord0.xyz);
}

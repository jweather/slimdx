/*
* Copyright (c) 2007-2008 SlimDX Group
* 
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
* 
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
* 
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
* THE SOFTWARE.
*/
#pragma once

#include "../ComObject.h"

#include "../dxgi/Enums.h"
#include "../math/Color4.h"

#include "Enums.h"

namespace SlimDX
{
	namespace Direct3D10
	{
		ref class Buffer;
		ref class DepthStencilView;
		ref class InputAssemblerWrapper;
		ref class InputLayout;
		ref class OutputMergerWrapper;
		ref class RasterizerWrapper;
		ref class RenderTargetView;
		ref class Resource;
		ref class ShaderResourceView;
		ref class StreamOutputWrapper;
		ref class SwapChain;
		value class CounterCapabilities;
		value class CounterDescription;
		value class CounterMetadata;
		value class RenderTargetViewDescription;
		value class ResourceRegion;
		value class SwapChainDescription;

		public ref class Device : ComObject
		{
			COMOBJECT(ID3D10Device, Device);
		
		private:
			InputAssemblerWrapper^ m_InputAssembler;
			OutputMergerWrapper^ m_OutputMerger;
			StreamOutputWrapper^ m_StreamOutput;
			RasterizerWrapper^ m_Rasterizer;

		public:
			property InputAssemblerWrapper^ InputAssembler
			{
				InputAssemblerWrapper^ get();
			}

			property OutputMergerWrapper^ OutputMerger
			{
				OutputMergerWrapper^ get();
			}

			property StreamOutputWrapper^ StreamOutput
			{
				StreamOutputWrapper^ get();
			}

			property RasterizerWrapper^ Rasterizer
			{
				RasterizerWrapper^ get();
			}
			
			property DeviceCreationFlags CreationFlags
			{
				DeviceCreationFlags get();
			}
			
			Device( DeviceCreationFlags flags );
			static Device^ FromPointer( System::IntPtr pointer );

			CounterCapabilities GetCounterCapabilities();
			CounterMetadata GetCounterMetadata( CounterDescription description );
			
			FormatSupport CheckFormatSupport( DXGI::Format format );
			int CheckMultisampleQualityLevels( DXGI::Format format, int sampleCount );
			
			void ClearDepthStencilView( DepthStencilView^ view, DepthStencilClearFlags flags, float depth, System::Byte stencil );
			void ClearRenderTargetView( RenderTargetView^ view, Color4 color );
			void ClearState();
			
			void CopyResource( Resource^ source, Resource^ destination );
			void CopySubresourceRegion( Resource^ source, int sourceSubresource, ResourceRegion region, Resource^ destination, int destinationSubresource, int x, int y, int z );
			void ResolveSubresource( Resource^ source, int sourceSubresource, Resource^ destination, int destinationSubresource, DXGI::Format format );
			
			void Draw( int vertexCount, int startVertexLocation );
			void DrawAuto();
			void DrawIndexed( int indexCount, int startIndexLocation, int baseVertexLocation );
			void DrawIndexedInstanced( int indexCountPerInstance, int instanceCount, int startIndexLocation, int baseVertexLocation, int startInstanceLocation );
			void DrawInstanced( int vertexCountPerInstance, int instanceCount, int startVertexLocation, int startInstanceLocation );
		
			void Flush();
			
			void GenerateMips( ShaderResourceView^ view );
		};
	}
};
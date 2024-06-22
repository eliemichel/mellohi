#pragma once

#include <vector>

#include <webgpu/webgpu.hpp>

namespace mellohi
{
    class Buffer
    {
    public:
        template <typename T>
        Buffer(const std::vector<T>& data, wgpu::BufferUsageFlags wgpu_usage_flags);
        virtual ~Buffer();

        wgpu::Buffer get_unsafe() const;

    private:
        wgpu::Buffer m_wgpu_buffer;

        void create_buffer(const void* data, size_t size, wgpu::BufferUsageFlags wgpu_usage_flags);
    };

    template<typename T>
    Buffer::Buffer(const std::vector<T>& data, const wgpu::BufferUsageFlags wgpu_usage_flags)
    {
        const size_t size = ((data.size() * sizeof(T)) + 3) & ~3;
        create_buffer(data.data(), size, wgpu_usage_flags);
    }


    class VertexBuffer final : public Buffer
    {
    public:
        template <typename T>
        explicit VertexBuffer(const std::vector<T>& data);

        void add_attribute_vec2f();
        void add_attribute_vec3f();

        wgpu::VertexBufferLayout get_wgpu_layout() const;

    private:
        std::vector<wgpu::VertexAttribute> m_wgpu_vertex_attributes;
        size_t m_stride;

        void add_attribute(wgpu::VertexFormat wgpu_format, size_t size);
    };

    template<typename T>
    VertexBuffer::VertexBuffer(const std::vector<T>& data)
        : Buffer(data, wgpu::BufferUsage::CopyDst | wgpu::BufferUsage::Vertex),
          m_stride(0) { }


    class IndexBuffer final : public Buffer
    {
    public:
        explicit IndexBuffer(const std::vector<uint16_t>& data);
        explicit IndexBuffer(const std::vector<uint32_t>& data);

        wgpu::IndexFormat get_wgpu_format() const;

    private:
        wgpu::IndexFormat m_wgpu_format;
    };
}
# Linux Diagnostic Tool 🔧

[![License](https://img.shields.io/badge/License-GPL--3.0-blue.svg)](LICENSE)
[![Platform](https://img.shields.io/badge/Platform-Linux-orange.svg)](https://www.linux.org/)
[![Language](https://img.shields.io/badge/Language-C-green.svg)](https://en.wikipedia.org/wiki/C_(programming_language))

> A comprehensive system diagnostic utility for Linux systems, built with performance and reliability in mind.

## 🎯 Overview

The Linux Diagnostic Tool is a professional-grade command-line utility designed for system administrators, DevOps engineers, and power users who need detailed insights into their Linux system's health and performance. Written in pure C for maximum efficiency and minimal overhead.

## ✨ Key Features

### 🖥️ System Information
- **CPU Metrics:** Real-time processor usage, core statistics, temperature monitoring
- **Memory Analysis:** RAM usage, swap utilization, cache statistics
- **Disk I/O:** Read/write operations, latency, throughput analysis
- **Network Interfaces:** Interface status, bandwidth usage, packet statistics

### 📊 Performance Diagnostics
- **Process Monitoring:** Top resource-consuming processes
- **Load Average:** System load trends and analysis
- **Interrupt Analysis:** Hardware and software interrupt rates
- **Context Switching:** Process scheduling statistics

### 🔍 Hardware Detection
- **CPU Information:** Model, cores, threads, cache sizes, flags
- **Memory Details:** Total, available, type, speed
- **Storage Devices:** Disk models, capacities, SMART status
- **PCI Devices:** Connected hardware enumeration

### 🚨 Health Monitoring
- **Temperature Sensors:** CPU, GPU, drive temperatures
- **Fan Speeds:** Cooling system status
- **Power Consumption:** Energy usage statistics (if supported)
- **Error Logs:** System and kernel error reporting

### 📝 Detailed Reporting
- **Export Options:** JSON, CSV, plain text formats
- **Historical Data:** Track metrics over time
- **Customizable Output:** Filter and format as needed
- **Automated Alerts:** Threshold-based notifications

## 🚀 Installation

### Prerequisites
- GCC compiler (version 5.0 or higher)
- Linux kernel headers
- Make utility
- Root/sudo access for some features

### Supported Distributions
- ✅ Arch Linux (primary development platform)
- ✅ Ubuntu/Debian
- ✅ Fedora/RHEL/CentOS
- ✅ OpenSUSE
- ✅ Most modern Linux distributions

### Build from Source

```bash
# Clone the repository
git clone https://github.com/W0nder0fy0u/linux-diagnostic-tool.git
cd linux-diagnostic-tool

# Compile the project
make

# Install system-wide (optional)
sudo make install

# Run the tool
./diag-tool
```

### Quick Install (Arch Linux)

```bash
# If you're on Arch Linux, you can use the provided PKGBUILD
makepkg -si
```

## 🎮 Usage

### Basic Commands

```bash
# Show all diagnostics
./diag-tool --all

# CPU diagnostics only
./diag-tool --cpu

# Memory diagnostics
./diag-tool --memory

# Disk I/O analysis
./diag-tool --disk

# Network statistics
./diag-tool --network

# System health overview
./diag-tool --health
```

### Advanced Usage

```bash
# Export to JSON
./diag-tool --all --output json > system_report.json

# Continuous monitoring (update every 2 seconds)
./diag-tool --monitor --interval 2

# Detailed CPU analysis
./diag-tool --cpu --detailed

# Show only warnings and errors
./diag-tool --health --severity warning

# Custom output formatting
./diag-tool --cpu --memory --format compact
```

### Command-Line Options

```
Usage: diag-tool [OPTIONS]

Diagnostic Options:
  --all               Run all diagnostic checks
  --cpu               CPU diagnostics and statistics
  --memory            Memory usage and analysis
  --disk              Disk I/O and storage information
  --network           Network interface statistics
  --health            System health overview
  --processes         Top processes by resource usage

Output Options:
  --output FORMAT     Output format (text|json|csv)
  --detailed          Show detailed information
  --format TYPE       Display format (full|compact|minimal)
  --quiet             Suppress non-critical messages

Monitoring:
  --monitor           Continuous monitoring mode
  --interval SEC      Update interval in seconds (default: 1)
  --duration SEC      Monitoring duration in seconds

General:
  --help              Display this help message
  --version           Show version information
  --verbose           Enable verbose output
```

## 📚 Code Structure

```
linux-diagnostic-tool/
├── src/
│   ├── main.c              # Entry point
│   ├── cpu.c               # CPU diagnostics
│   ├── memory.c            # Memory analysis
│   ├── disk.c              # Disk I/O monitoring
│   ├── network.c           # Network statistics
│   ├── health.c            # Health monitoring
│   ├── process.c           # Process management
│   ├── sensors.c           # Temperature/fan sensors
│   ├── utils.c             # Utility functions
│   └── output.c            # Output formatting
├── include/
│   ├── diag.h              # Main header
│   ├── cpu.h               # CPU functions
│   ├── memory.h            # Memory functions
│   ├── disk.h              # Disk functions
│   ├── network.h           # Network functions
│   └── utils.h             # Utility functions
├── tests/                  # Unit tests
├── docs/                   # Documentation
│   ├── API.md              # API documentation
│   └── EXAMPLES.md         # Usage examples
├── Makefile                # Build configuration
├── README.md               # This file
└── LICENSE                 # GPL-3.0 License
```

## 🔧 Technical Details

### System Calls Used
- `/proc` filesystem parsing for system information
- `/sys` filesystem for hardware details
- `sysinfo()` for system statistics
- `getifaddrs()` for network interfaces
- `statvfs()` for filesystem information

### Performance Considerations
- Minimal memory footprint (~2-5 MB)
- Efficient algorithms for real-time monitoring
- No external dependencies beyond standard C library
- Direct system calls for maximum performance
- Optimized for low-latency environments

### Security
- Requires appropriate permissions for certain operations
- Safe handling of system files and resources
- Input validation and bounds checking
- No privileged information exposure

## 🤝 Contributing

Contributions are highly encouraged! Here's how you can help:

### Ways to Contribute
- 🐛 Report bugs and issues
- 💡 Suggest new features
- 📝 Improve documentation
- 🔧 Submit bug fixes
- ✨ Add new diagnostic modules

### Development Setup

```bash
# Fork and clone your fork
git clone https://github.com/YOUR_USERNAME/linux-diagnostic-tool.git
cd linux-diagnostic-tool

# Create a feature branch
git checkout -b feature/your-feature-name

# Make your changes and test
make clean
make
make test

# Commit and push
git commit -m "Add your feature"
git push origin feature/your-feature-name

# Create a Pull Request
```

### Coding Standards
- Follow the Linux kernel coding style
- Comment complex logic
- Include unit tests for new features
- Update documentation as needed
- Ensure no memory leaks (use Valgrind)

## 🧪 Testing

```bash
# Run all tests
make test

# Run specific test
./tests/test_cpu

# Memory leak check with Valgrind
valgrind --leak-check=full ./diag-tool --all

# Performance profiling
perf record ./diag-tool --all
perf report
```

## 📋 Roadmap

### Version 2.0 (Planned)
- [ ] GPU diagnostics support (NVIDIA/AMD)
- [ ] Docker container monitoring
- [ ] Web-based dashboard
- [ ] Historical data visualization
- [ ] Email/SMS alerting
- [ ] Plugin system for custom modules

### Version 2.1 (Future)
- [ ] Predictive failure analysis
- [ ] Machine learning anomaly detection
- [ ] Cluster monitoring support
- [ ] REST API for remote monitoring
- [ ] Mobile app integration

## 🐛 Known Issues

- Temperature readings may not work on virtual machines
- Some network statistics require root privileges
- SMART data unavailable for NVMe drives on older kernels

See the [issue tracker](https://github.com/W0nder0fy0u/linux-diagnostic-tool/issues) for more details.

## 📖 Documentation

For detailed documentation, see:
- [API Reference](docs/API.md)
- [Usage Examples](docs/EXAMPLES.md)
- [Architecture Overview](docs/ARCHITECTURE.md)

## 📄 License

This project is licensed under the GNU General Public License v3.0 - see the [LICENSE](LICENSE) file for details.

## 👨‍💻 Author

**Subham Tiwari**
- GitHub: [@W0nder0fy0u](https://github.com/W0nder0fy0u)
- Email: [](mailto:)

## 🙏 Acknowledgments

- Inspired by tools like `htop`, `glances`, and `sysstat`
- Built for the Arch Linux community
- Thanks to all contributors and testers

## 💬 Support

If you need help:
- 📖 Check the [documentation](docs/)
- 🐛 [Open an issue](https://github.com/W0nder0fy0u/linux-diagnostic-tool/issues)
- 💬 Start a [discussion](https://github.com/W0nder0fy0u/linux-diagnostic-tool/discussions)

## ⭐ Show Your Support

If this tool helped you, please give it a ⭐ on GitHub!

---

**Built with ⚡ for Linux system administrators and enthusiasts**

*Optimized for Arch Linux | Compatible with most modern distributions*

*Last Updated: February 2026*

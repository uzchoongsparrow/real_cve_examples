# Security Vulnerabilities Implementation Repository

## Overview

This repository contains code implementations of various famous security vulnerabilities for research and educational purposes. It serves as a benchmarking tool for Security-as-a-Service (SecaaS) solutions, enabling users to evaluate and compare the effectiveness of these security services in detecting and mitigating vulnerabilities. The implementations include Follina in Go, Heartbleed Proof of Concept (PoC) in C++, and a Spring4Shell vulnerability example.

## Disclaimer

The code within this repository is intended **solely for educational and research purposes**. It aims to increase awareness and understanding of security vulnerabilities and should not be used for illegal activities. The maintainers of this repository do not condone misuse of this code and are not responsible for any damages or legal consequences resulting from such misuse. By accessing and using this repository, you agree to use it in a responsible and ethical manner.

## Vulnerability Implementations

### Follina (CVE-2022-30190) in Go

- **Description**: Follina is a code execution vulnerability that exploits a flaw in the Microsoft Windows Support Diagnostic Tool (MSDT) when processing specially crafted Microsoft Office documents. Even without macros enabled, an attacker could execute arbitrary code through a document that contains a malicious MSDT URL. This Go implementation aims to simulate the vulnerability's exploitation mechanism without relying on actual Office documents.
- **Impact**: Allows attackers to execute arbitrary code on a target system, potentially leading to system compromise.

### Heartbleed (CVE-2014-0160) PoC in C++

- **Description**: Heartbleed is a severe vulnerability in the OpenSSL cryptographic software library. This bug allows stealing the information protected, under normal conditions, by the SSL/TLS encryption used to secure the Internet. SSL/TLS provides communication security and privacy over the Internet for applications such as web, email, instant messaging (IM), and some virtual private networks (VPNs). The C++ PoC demonstrates how the vulnerability could be exploited to read memory of servers running affected versions of OpenSSL.
- **Impact**: Exposes sensitive data from the server's memory, including private keys, user passwords, and personal user information, potentially leading to further attacks.

### Spring4Shell (CVE-2022-22965)

- **Description**: Spring4Shell is a remote code execution vulnerability in the Spring Framework. It arises from improper handling of data binding scenarios, allowing attackers to inject malicious data through crafted HTTP requests. This example demonstrates how an application built with the Spring Framework might be exploited through data binding vulnerabilities to execute arbitrary code on the server.
- **Impact**: Enables unauthorized remote code execution, allowing attackers to gain control over affected servers.

## Usage

Before running any of the provided vulnerability examples, ensure that you are operating in a safe and controlled environment. These examples are intended for testing and research purposes only and should not be deployed or executed in any production environment.

## Contributing

Contributions to this repository are welcome. If you have an implementation of a security vulnerability or an improvement to an existing example, please feel free to submit a pull request. Ensure that all contributions adhere to ethical guidelines and are intended for educational purposes only.

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE) file for details.

## Acknowledgments

- All contributors and users are reminded to use this repository responsibly and ethically.
- This project is for educational purposes and aims to contribute to the cybersecurity community's efforts in understanding and mitigating vulnerabilities.

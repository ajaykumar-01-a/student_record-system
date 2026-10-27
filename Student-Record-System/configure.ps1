# Configuration Script for Student Record System
# This script configures the project with CMake for the first time

# Add MinGW to PATH
$env:Path = "C:\mingw64\bin;" + [System.Environment]::GetEnvironmentVariable("Path","Machine") + ";" + [System.Environment]::GetEnvironmentVariable("Path","User")

Write-Host "=== Student Record System Configuration ===" -ForegroundColor Cyan
Write-Host ""

# Clean old build directory if it exists
if (Test-Path "build") {
    Write-Host "Cleaning old build directory..." -ForegroundColor Yellow
    Remove-Item -Recurse -Force build
}

# Configure with CMake
Write-Host "Configuring project with CMake..." -ForegroundColor Yellow
cmake -S . -B build -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release

if ($LASTEXITCODE -ne 0) {
    Write-Host "Configuration failed!" -ForegroundColor Red
    exit 1
}

Write-Host ""
Write-Host "Configuration succeeded!" -ForegroundColor Green
Write-Host ""
Write-Host "Next steps:" -ForegroundColor Cyan
Write-Host "  1. Run .\build-and-run.ps1 to build, test, and run" -ForegroundColor White
Write-Host "  2. Or manually: cmake --build build --config Release" -ForegroundColor White
